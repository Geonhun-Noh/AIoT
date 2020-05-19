import numpy as np
import pandas as pd

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression

df_titanic = pd.read_csv('train.csv')
df_y_titanic = df_titanic['Survived']
df_x_titanic = df_titanic.drop('Survived',axis=1)
#df_x_titanic = complete_df(df_x_titanic)

x_train,x_test,y_train,y_test=train_test_split(df_x_titanic,df_y_titanic,test_size=0.20,random_state=11)

from sklearn.metrics import precision_recall_curve

lr_clf = LogisticRegression()
pred_proba_class1 = lr_clf.predict_proba(x_test)[:1]
print(pred_proba_class1)

precisions, recalls, thresholds = precision_recall_curve(y_test,pred_proba_class1)
