import graphviz

from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import export_graphviz

dt_clf = DecisionTreeClassifier(random_state=156)

iris = load_iris()
x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target,
                                                    test_size=0.2, random_state=11)

dt_clf.fit(x_train, y_train)

export_graphviz(dt_clf, out_file='tree.dot', class_names=iris.target_names,
                feature_names=iris.feature_names, impurity=True, filled=True)

with open('tree.dot') as f:
    dot_graph = f.read()
    
graphviz.Source(dot_graph)

###############################
#max_depth =3, min_samples_split=4, min_samples_leaf=4로 의사결정나무 그리기 
import graphviz

from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import export_graphviz

dt_clf = DecisionTreeClassifier(random_state=156, min_samples_split=4,min_samples_leaf=4)
dtree = DecisionTreeClassifier()

iris = load_iris()
x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target,
                                                    test_size=0.2, random_state=11)

dt_clf.fit(x_train, y_train)


export_graphviz(dt_clf, out_file='/content/gdrive/My Drive/AIoT/tree.dot', class_names=iris.target_names,
                feature_names=iris.feature_names, max_depth=3, impurity=True, filled=True)

with open('/content/gdrive/My Drive/AIoT/tree.dot') as f:
    dot_graph = f.read()
    
graphviz.Source(dot_graph)