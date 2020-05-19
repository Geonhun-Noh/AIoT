from flask import Flask, request, jsonify
from flaskext.mysql import MySQL
app = Flask(__name__)

app.config['MYSQL_DATABASE_HOST'] = 'team04.ckzbwnwwxarf.ap-northeast-2.rds.amazonaws.com'
app.config['MYSQL_DATABASE_USER'] = 'admin'
app.config['MYSQL_DATABASE_PASSWORD'] = 'asdqwe123#team04'
app.config['MYSQL_DATABASE_DB'] = 'IoT_Project'

mysql = MySQL()
mysql.init_app(app)

@app.route('/project/tag', methods=['POST'])
def tag_value():
    body = request.json
    emp_id = body['emp_id']
    type = body['tag_type']

    cursor = mysql.get_db().cursor()
    cursor.execute("insert into Tag (emp_id,tag_type) values (%s,%s)",(emp_id,type))

    mysql.get_db().commit()

    return jsonify({"message": "success"})


if __name__ == '__main__':
    app.run(debug=True)