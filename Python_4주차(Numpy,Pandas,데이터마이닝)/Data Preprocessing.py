###### 데이터 전처리 #######

from sklearn.preprocessing import LabelEncoder
items=['TV','냉장고','전자렌지','컴퓨터','선풍기','선풍기','믹서','믹서']

encoder=LabelEncoder()
encoder.fit(items)
labels=encoder.transform(items)
print('Label encoding result:',labels)

print('Encoding classes:',encoder.classes_)
print('Decoding values:',encoder.inverse_transform([4,5,2,0,1,1,3,3]))

##### One-Hot Encoding #####
#카테고리 값의 개수를 원소 개수로 하는 배열 생성
# 카테고리 값에 해당하는 위치만 값을 '1'로 지정, 나머지는 '0'으로 지정

from sklearn.preprocessing import OneHotEncoder
import numpy as np

items=['TV','냉장고','전자렌지','컴퓨터','선풍기','계산기','믹서','믹서']

encoder = LabelEncoder()
encoder.fit(items)
lables = encoder.transform(items)
labels = labels.reshape(-1,1)

one_hot_encoder=OneHotEncoder()
one_hot_encoder.fit(labels)
one_hot_encoder=one_hot_encoder.transform(labels)


print('One-Hot Encoder Data')
print(one_hot_encoder.toarray())
print('Demension of Encoding Data')
print(one_hot_encoder.shape)

##### Pandas API #####
import pandas as pd
df = pd.DataFrame({'item':['TV','냉장고','전자렌지','컴퓨터','선풍기','믹서']})
print(pd.get_dummies(df))


            ##########################
            ######## Scaling #########
            ##########################
            
from sklearn.datasets import load_iris
import pandas as pd

iris=load_iris()
iris_data=iris.data
df_iris=pd.DataFrame(data=iris_data,columns=iris.feature_names)

print('Average') #평균
print(df_iris.mean())
print('\nVariance') #분산, 일반적으로 분산이 클 수록 주요 요인이 될 가능성이 크다.
print(df_iris.var())

###StandardScaler를 이용한 Standardization ###
from sklearn.preprocessing import StandardScaler

scaler=StandardScaler()
scaler.fit(df_iris)
scaled_iris=scaler.transform(df_iris)

df_scaled_iris=pd.DataFrame(data=scaled_iris,columns=iris.feature_names)

print('\nAverage')
print(df_scaled_iris.mean())
print('\nVariance')
print(df_scaled_iris.var())

### MinMaxScaler() API : Normalization을 쉽게 수행 ###
# 데이터의 값의 범위를 0~1 사이로 변환
# BUT Gaussian Normal Distribution으로 변환되는 것은 아님
from sklearn.preprocessing import MinMaxScaler

scaler = MinMaxScaler()
scaler.fit(df_iris)
scaled_iris=scaler.transform(df_iris)

df_scaled_iris=pd.DataFrame(data=scaled_iris,columns=iris.feature_names)

print('\nMin value')
print(df_scaled_iris.min())
print('\nMax value')
print(df_scaled_iris.max())
print('\nAverage')
print(df_scaled_iris.mean())
print('\nVariance')
print(df_scaled_iris.var())