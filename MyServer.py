from flask import Flask, request, jsonify, render_template
from flaskext.mysql import MySQL
app = Flask(__name__)

app.config['MYSQL_DATABASE_HOST'] = 'localhost'
app.config['MYSQL_DATABASE_USER'] = 'root'
app.config['MYSQL_DATABASE_PASSWORD'] = 'crystal7260'
app.config['MYSQL_DATABASE_DB'] = 'aiot_database'

mysql = MySQL()
mysql.init_app(app)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/basic')
def basic():
    return render_template('basic.html')

@app.route('/test')
def test():
    return render_template('test.html')


@app.route('/work')
def work():
    return render_template('work.html')

@app.route('/test_work')
def test_work():
    return render_template('work.html')



# tag시 tag table에 insert
@app.route('/emp_id/tag', methods=['POST'])
def post_tag_table():
    body = request.json
    id = body['emp_id']
    time = body['tag_time']
    type = body['tag_type']

    cursor = mysql.get_db().cursor()

    cursor.execute("insert into Tag (emp_id, tag_time, tag_type) values (%s, %s, %s)", (id, time, type))

    mysql.get_db().commit()

    return jsonify({"message": "success"})


# 근무시간 조회
@app.route('/work/<emp_id>/<sdate>/<edate>')
def get_work_time(emp_id,sdate, edate):
    cursor = mysql.get_db().cursor()
    cursor.execute("select * from work_time WHERE date(working_date) >= date(%s) and date(working_date) <= date(%s) and emp_id=%s",
                   (sdate, edate, emp_id))


    row_headers = [x[0] for x in cursor.description]

    result = cursor.fetchall()
    json_data=[]
    for result in result:
        json_data.append(dict(zip(row_headers, result)))

    for data in json_data:
        data['working_time'] = str(data['working_time'])
    return jsonify(json_data)



@app.route('/orderitems/<prod_id>/values/latest')
def get_latest_sensor_value(prod_id):
    cursor = mysql.get_db().cursor()
    cursor.execute("select * from orderitems where prod_id=%s order by order_num desc", prod_id)

    row_headers = [x[0] for x in cursor.description]

    result = cursor.fetchall()
    print(result)
    print(row_headers)
    json_data=[]
    for result in result:
        json_data.append(dict(zip(row_headers, result)))
    for data in json_data:
        data['item_price']=str(data['item_price'])
    return jsonify(json_data)


@app.route('/orderitems/<prod_id>/values/<page>')
def get_sensor_values(prod_id, page):
    cursor = mysql.get_db().cursor()

    offset = (int(page) - 1) * 10

    cursor.execute("select * from aiot_database.orderitems where prod_id=%s order by item_price desc limit 10 offset %s", (prod_id, offset))

    row_headers = [x[0] for x in cursor.description]

    result = cursor.fetchall()

    json_data = []
    for result in result:
        json_data.append(dict(zip(row_headers, result)))

    return jsonify({"values": json_data})


@app.route('/orderitems/value', methods=['POST'])
def post_sensor_value():
    body = request.json
    prod_id = body['prod_id']
    quantity = body['quantity']
    order_num = body['order_num']
    order_item = body['order_item']
    price = body['price']

    cursor = mysql.get_db().cursor()
    cursor.execute("insert into orderitems (prod_id, quantity,order_num,order_item,item_price) values (%s, %s,%s,%s,%s)", (prod_id, quantity, order_num,order_item,price))

    mysql.get_db().commit()

    return jsonify({"message": "success"})


if __name__ == '__main__':
    app.run(debug=True)