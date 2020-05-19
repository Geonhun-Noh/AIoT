import sklearn
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, confusion_matrix
from sklearn.metrics import roc_curve
from sklearn.preprocessing import LabelEncoder
from sklearn.linear_model import LogisticRegression



# Null 데이터를 처리하는 함수
def fillna(df):
    df['Age'].fillna(df['Age'].mean(), inplace=True)
    df['Cabin'].fillna('N', inplace=True)
    df['Embarked'].fillna('N', inplace=True)
    df['Fare'].fillna(0,inplace=True)
    return df

#불필요한 속성 제거 함수
def drop_col(df):
    df.drop('Name',axis=1,inplace=True) #axis가 0이면 row, 1이면 column !
    df.drop('Ticket',axis=1,inplace=True)
    df.drop('PassengerId',axis=1,inplace=True)
    return df

#Labeling Encoding
#print(df_titanic['Cabin'])
def encode_feature(df):
    encoder=LabelEncoder()
    df['Cabin']=df['Cabin'].str[:1]
    features=['Cabin','Sex','Embarked']
    for feature in features:
        encoder.fit(df[feature])
        labels=encoder.transform(df[feature])
        df[feature]=labels
    return df

#전처리 함수
def complete_df(df):
    df=fillna(df)
    df=drop_col(df)
    df=encode_feature(df)
    #df['Age_cat']=df['Age'].apply(lambda x : get_category(x))
    #df['Family']=df[['SibSp', 'Parch','Age']].apply(lambda x,y,z: is_family(x,y,z))
    return df


# Confusion Matrix, Accuracy, Precision, Recall 도출 함수
def get_clf_eval(y_test,pred):
    confusion=confusion_matrix(y_test,pred)
    accuracy=accuracy_score(y_test,pred)
    precision=precision_score(y_test,pred)
    recall=recall_score(y_test,pred)
    
    print('Confusion Matrixs')
    print(confusion)
    print('Accuracy:{0:0.4f},Precision:{1:0.4f},Recall:{2:0.4f}'.format(accuracy,precision,recall))