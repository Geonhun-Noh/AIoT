from flask import Flask,request   # Flask 모듈을 사용하기 위한 설정

app = Flask(__name__)

@app.route('/sensor/data/list')
def get_sensor_data_list():
    data1= {"device_id":"LED01","data":"on","datetime":"20190731 00:12:47"}
    data2= {"device_id":"LED02","data":"off","datetime":"20190731 00:58:47"}

    list = [data1,data2]
    response = {"data_list":list}
    print(response)

    return response

if __name__  == '__main__':
    app.run(debug=True)