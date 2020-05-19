from flask import Flask  # Flask 모듈을 사용하기 위한 설정

app = Flask(__name__)

@app.route('/')  # url 창에 localhost:5000을 입력하면 아래 함수 실행. '/' 뒤에 더 붙이면 그 내용을 입력해야 실행
def index():
    return "Moo Kyung is Solo"

if __name__  == '__main__':
    app.run(debug=True)