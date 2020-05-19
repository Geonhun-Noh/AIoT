from flask import Flask, request, jsonify
from flaskext.mysql import MySQL
app = Flask(__name__)

app.config['MYSQL_DATABASE_HOST'] = 'team06.ckzbwnwwxarf.ap-northeast-2.rds.amazonaws.com'
app.config['MYSQL_DATABASE_USER'] = 'admin'
app.config['MYSQL_DATABASE_PASSWORD'] = 'asdqwe123#team06'
app.config['MYSQL_DATABASE_DB'] = 'aiot'

mysql = MySQL()
mysql.init_app(app)


@app.route('/sensor/<sensor_id>/value/latest')
def get_latest_sensor_value(sensor_id):
    cursor = mysql.get_db().cursor()
    cursor.execute("select * from sensor_data where sensor_id=%s order by datetime desc limit 1", sensor_id)

    row_headers = [x[0] for x in cursor.description]

    result = cursor.fetchone()

    json_data = dict(zip(row_headers, result))

    return jsonify(json_data)


@app.route('/sensor/<sensor_id>/values/<page>')
def get_sensor_values(sensor_id, page):
    cursor = mysql.get_db().cursor()

    offset = (int(page) - 1) * 10

    cursor.execute("select * from sensor_data where sensor_id=%s order by datetime desc limit 10 offset %s", (sensor_id, offset))

    row_headers = [x[0] for x in cursor.description]

    result = cursor.fetchall()

    json_data = []
    for result in result:
        json_data.append(dict(zip(row_headers, result)))

    return jsonify({"values": json_data})


@app.route('/sensor/value', methods=['POST'])
def post_sensor_value():
    body = request.json
    sensor_id = body['sensor_id']
    value = body['value']

    cursor = mysql.get_db().cursor()
    cursor.execute("insert into sensor_data (sensor_id, value) values (%s, %s)", (sensor_id, value))

    mysql.get_db().commit()

    return jsonify({"message": "success"})


if __name__ == '__main__':
    app.run(debug=True)