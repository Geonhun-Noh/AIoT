from flask import Flask, request, jsonify
from flaskext.mysql import MySQL
app = Flask(__name__)

app.config['MYSQL_DATABASE_HOST   '] = 'localhost'
app.config['MYSQL_DATABASE_USER'] = 'root'
app.config['MYSQL_DATABASE_PASSWORD'] = 'crystal7260'
app.config['MYSQL_DATABASE_DB'] = 'aiot_database'

mysql = MySQL()
mysql.init_app(app)


@app.route('/temperature/sensor/data', methods=['POST'])
def post_sensor_value():
    body = request.json
    value = body['value']

    cursor = mysql.get_db().cursor()
    cursor.execute("insert into temperature_sensor_data (value) values (%s)", value)

    mysql.get_db().commit()

    return jsonify({"message": "success"})

if __name__ == '__main__':
    app.run(debug=True)