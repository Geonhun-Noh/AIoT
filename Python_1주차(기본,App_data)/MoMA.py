opened_file=open('artworks.csv',encoding='UTF8')
from csv import reader
read_file = reader(opened_file)
moma=list(read_file)
moma=moma[1:]

#print(moma[1:4])

for data in moma:   #Nationality, Gender ()제거
    nationality=data[2]
    nationality = nationality.replace('(','')
    nationality = nationality.replace(')','')
    data[2] = nationality.title()
    
    gender=data[5]
    gender=gender.replace('(','').replace(')','')
    data[5]=gender.title()
    
for data in moma:  #Gender 빈 문자열 삽입
    gender = data[5]
    gender=gender.title()
    if not gender:
        gender="Gender Unknown/Other"
    data[5]=gender
    
for data in moma:   #Nationality 빈 문자열 삽입
    nationality = data[2]
    if not nationality:
        nationality = "Nationality Unknown"
        
def clean_and_convert(date):   #date 의 ()제거, 빈 문자열 넣는 함수 정의
    if date:
        a=date.replace('(','').replace(')','')
        date=int(a)
    else:
        date=0
    return date


######test_data와 bad_char을 활용한 함수 정의
test_data=['1912','1929','1913-1923','(1951)','1994','1934','c. 1915','1995',
           'c. 1912','(1988)','2002','1957-1959','c. 1955.','1957-1959','c. 1955',
           "c. 1970's",'C. 1990-1999']
bad_char=["(",")","c","C",".","s","'"," "]
        
def strip_characters(str):   
    for data in bad_char:
        str= str.replace(data,"")
    return str

strip_data=[]   #strip_data 정의 : bad_char 삭제
for data in test_data:
    a=strip_characters(data)
    strip_data.append(a)
#print('strip_data:\n',strip_data)


stripped_test_data=[] #bad_char와 '-'가 제거된 test_data 리스
for year in test_data:
    
    if '-' in year:   # test_data에 '-'가 포함된 연도는 평균값으로 계산
        a=strip_characters(year)
        single=a.split('-')
        sum=0
        n=len(single)
        for i in range(n):
            sum+=int(single[i])
        avg=sum/n
        stripped_test_data.append(round(avg))
        #print(round(avg))
    else:
        a=strip_characters(year)
        stripped_test_data.append(int(a))
        #print(a)
#print('stripped_test_data:\n',stripped_test_data)
#print(moma[:3])


def process_date(string):
    result = 0
    if "-" in string:
        begin, end = string.split('-')
        begin = int(begin)
        end = int(end)
        result = round((begin + end) / 2)
    else:
        result = int(string)
    
    return result

for data in strip_data:
    stripped_test_data = process_date(data)
    #print(stripped_test_data)

date=[]
for data in moma:
    a=strip_characters(data[6])
    b=process_date(a)
    date.append(b)
    data[6]=date
print(moma)

















