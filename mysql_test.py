from flask import Flask, jsonify
from flaskext.mysql import MySQL

app = Flask(__name__)

app.config['MYSQL_DATABASE_HOST'] = 'localhost'
app.config['MYSQL_DATABASE_USER'] = 'root'
app.config['MYSQL_DATABASE_PASSWORD'] = 'crystal7260'
app.config['MYSQL_DATABASE_DB'] = 'aiot_database'

mysql = MySQL()
mysql.init_app(app)

'''
@app.route('/customer')
def get_one_customer():
    cursor = mysql.get_db().cursor()
    cursor.execute("select * from customers where cust_id=%s", '1000000002')
    row_headers = [x[0] for x in cursor.description] # column의 이름을 뽑아내기 위한 쿼리
    result = cursor.fetchone() # fetchone : 아이디를 기반으로 하나의 데이터만을 뽑아내기 위한 쿼리
    print(result)
    json_data = dict(zip(row_headers, result))
    return jsonify(json_data)
'''
@app.route('/customers')
def get_customers():
    cursor = mysql.get_db().cursor()
    cursor.execute("select * from customers")
    print(cursor.description)
    row_headers = [x[0] for x in cursor.description]
    result = cursor.fetchall()
    print(result)
    json_data = []
    for result in result:
        json_data.append(dict(zip(row_headers, result)))
    return jsonify(json_data)

if __name__ == '__main__':
    app.run(debug=True)