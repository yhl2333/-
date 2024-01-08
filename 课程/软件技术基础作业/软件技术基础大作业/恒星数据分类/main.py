import numpy as np
import pandas as pd
import sklearn
from sklearn.model_selection import train_test_split
from xgboost.sklearn import XGBClassifier
from sklearn.preprocessing import OneHotEncoder
from sklearn.metrics import accuracy_score, make_scorer,confusion_matrix
from sklearn.model_selection import GridSearchCV
from xgboost.sklearn import XGBClassifier
import xgboost
import matplotlib.pyplot as plt
import seaborn as sns


data = pd.read_csv('train.csv')
print(data.head())
print('-'*100)
#查看数据类型
print(data.info())
print('-'*100)
#查看数据中位数、最大最小值分布等信息
print(data.describe())

#通过上述探索数据，发现data并无缺失值，根据提示，探究数据是否存在只有一个值的情况
for column in data.columns:
    if len(data[column].unique()) == 1:
        print(f'data:{column}')
        data.drop(column,axis=1,inplace=True)

data.drop(['obj_ID'],axis=1,inplace=True)
data.drop(['id'],axis=1,inplace=True)

def random_oversample(data,target_column):
    max_size = data[target_column].value_counts().max()
    print(max_size)
    lst = [data]
    print(lst)
    for class_index,group in data.groupby(target_column):
        lst.append(group.sample(max_size-len(group),replace=True))
    return pd.concat(lst)


new_data = random_oversample(data,'label')


label = new_data['label']
features = new_data.drop(['label'], axis=1)
model = XGBClassifier()
model.fit(features, label)
# 可视化排名前十的字段
xgboost.plot_importance(model, max_num_features=15)
plt.show()


x_train_1, x_test_1, y_train, y_test = train_test_split(new_data.drop(['label'],axis=1), label, test_size=0.2, random_state=10) #random_state保证每次运行拆分得到的结果一样
train_index = x_train_1.index #保证第二次拆分的时候，得到的训练集和测试集是一样的
test_index = x_test_1.index







importances_features_new_data = new_data[['redshift','g','u','z','i']]
x_train_2 = importances_features_new_data.iloc[train_index]
x_test_2 = importances_features_new_data.iloc[test_index]
#利用训练集进行模型的训练
#初始化XGBoost分类模型
modle_2 = XGBClassifier()
#在训练集上训练XGBoost模型
modle_2.fit(x_train_2, y_train)
#利用训练好的模型在测试集上进行预测
y_pred_2 = modle_2.predict(x_test_2)
#构建评分标准
accuracy = accuracy_score(y_test, y_pred_2)
print(f"Accuracy: {accuracy:.3f}")



data_test = pd.read_csv('test.csv')
importances_features_test_data = new_data[['redshift','g','u','z','i']]
y_pred_test = modle_2.predict(importances_features_test_data)
print(y_pred_test)

data = {'id': range(1, len(y_pred_test) + 1), 'label': y_pred_test}
df = pd.DataFrame(data)

# 将 DataFrame 保存为 CSV 文件
df.to_csv('sample_submission.csv', index=False)