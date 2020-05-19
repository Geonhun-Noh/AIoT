def open_dataset(header=True,file_name='AppleStore.csv'):
    
    opened_file =open(file_name,encoding='UTF8')
    from csv import reader
    read_file=reader(opened_file)
    data=list(read_file)
    if header:
        header=data[0]
        content = data[1:]        
        data_tuple=(header,content)
        return data_tuple
    else:
        return data





def explore_data(dataset,start,end,rows_and_columns=False):
    dataset_slice = dataset[start:end]
    for row in dataset_slice:
        print(row)
        print('\n') #adds a new (empty) line after each row
        
    if rows_and_columns:
        print('Number of rows: ',len(dataset))
        print('Number of columns: ', len(dataset[0]))
        

sub_ios = open_dataset()
ios=sub_ios[1]
#print(ios)
sub_android = open_dataset(file_name='googleplaystore.csv')
android=sub_android[1]
#print(android)


#explore_data(ios,0,10,True)
#explore_data(android,0,10,True)
#####확인

#의미있는 cloumn 확인

android_header = sub_android[0]
#



def find_rating(dataset,index1,index2,index3):
    rate_list=[]
    for data in dataset:
        if float(data[index1]) < 2.5 and float(data[index2])==0:
            rate_list.append(data[index3])
    return rate_list


ios_rate=find_rating(ios,7,4,1)
#print(ios_rate)
#print(len(ios_rate))

#android_rate=find_rating(android,2,7,0)
#print(android_rate)
#print(len(android_rate))
'''
print(android[10472]) #incorrect row
print('\n')
print(android_header) 
print('\n')
print(android[0])


print(len(android))
del android[10472]'''
'''
for app in android:
    name=app[0]
    if name == 'Instagram':
 #       print(app)

#duplicate_apps=[]
#unique_apps=[]

'''
'''pp in android:
    name=app[0]
    if name in unique_apps:
        duplicate_apps.append(name)
    else:
        unique_apps.append(name)
        
print('Number of duplicate apps: ', len(duplicate_apps))
print('\n')
print('Examples of duplicate apps: ',len(duplicate_apps[:15]))
'''
def is_english(string):
    for character in string:
        if ord(character) > 127:
            return False
    return True

android_english=[]
for app in android:
    name=app[0]
    
    if is_english(name):
        android_english.append(app)
        
#print(android_english)


def freq_table(a:int):
    dic = {}
    for data in apps_data[1:]:
        key = data[a]
        if key in dic:
            dic[key] += 1
        else :
            dic[key] = 1
    return dic

