### Part One
#1.
install.packages("titanic")
library(titanic)
### installin packages for data
titanic_train[,2]=as.factor(titanic_train[,2])
### setting column 2 as numerical factors

#2.
### put all 6 variables in a new table
data <- titanic_train[,c("Survived","Pclass","Sex","Age","SibSp","Parch")]

#3.
### set seed number 
set.seed(587)
### put the data into 3 sections and everything section has two parts, training and testing
indices <- split(sample(nrow(data), nrow(data),replace=FALSE), as.factor(1:3))
test_set1 <- data[indices[[1]],]
train_set1 <- data[-indices[[1]],]

test_set2 <- data[indices[[2]],]
train_set2 <- data[-indices[[2]],]

test_set3 <- data[indices[[3]],]
train_set3 <- data[-indices[[3]],]

### Part Two 
#1.
### installing packages and library
install.packages("e1071")
library(e1071)

### set up the naive Bayes models with those three sections of data
NB1 <- naiveBayes(Survived~., data=train_set1)
NB2 <- naiveBayes(Survived~., data=train_set2)
NB3 <- naiveBayes(Survived~.,data= train_set3)

### a prediction based on the models
predict(NB1,test_set1[,2:6])
predict(NB2,test_set2[,2:6])
predict(NB3,test_set3[,2:6])

#2.
### getting the tables to be a confusion matrix to use
table1=table(predict(NB1, test_set1[,2:6]), test_set1[,1])
table2=table(predict(NB2, test_set2[,2:6]), test_set2[,1])
table3=table(predict(NB3, test_set3[,2:6]), test_set3[,1])

#3. second row is column entries for determining sensitivity 
### first row is column entries for determining specificity 
### [2,2] is the true position ,[1,1] is the  true negative
sensitivity1=table1[2,2]/(table1[2,1]+table1[2,2])
specificity1=table1[1,1]/(table1[1,1]+table1[1,2])


sensitivity2=table2[2,2]/(table2[2,1]+table2[2,2])
specificity2=table2[1,1]/(table2[1,1]+table2[1,2])


sensitivity3=table3[2,2]/(table3[2,1]+table3[2,2])
specificity3=table3[1,1]/(table3[1,1]+table3[1,2])

#4.
### averaging all the sensitivities and specificities 
Avg_sensitivity=(sensitivity1+sensitivity2+sensitivity3)/3 
Avg_specificity=(specificity1+specificity2+specificity3)/3

### documentation for step 5, 6, 7 are the same with 2, 3, 4 
### They are the same because those are just reported steps.

#5.
table11=table(predict(NB1, train_set1[,2:6]), train_set1[,1])
table22=table(predict(NB2, train_set2[,2:6]), train_set2[,1])
table33=table(predict(NB3, train_set3[,2:6]), train_set3[,1])


#6.
sensitivity11=table11[2,2]/(table11[2,1]+table11[2,2])
specificity11=table11[1,1]/(table11[1,1]+table11[1,2])


sensitivity22=table22[2,2]/(table22[2,1]+table22[2,2])
specificity22=table22[1,1]/(table22[1,1]+table22[1,2])


sensitivity33=table33[2,2]/(table33[2,1]+table33[2,2])
specificity33=table33[1,1]/(table33[1,1]+table33[1,2])

#7.
Avg_sensitivity1=(sensitivity11+sensitivity22+sensitivity33)/3 
Avg_specificity1=(specificity11+specificity22+specificity33)/3


#8. 
### The confusion matrix was builded base one the table, and table uses the predict command to preceded the
### Naive Bayes model with train_sets data, then tabled with the test data verus the train data in step 4 and 7.
### Since predict(NB,....) is simply giving a prediction of the first column, and tabled with the actual 1 column
### Since uses the cross-classifying factors to build a contingency table of the counts at each combination of factor levels.
### and step 7 are using same data sets to construct the table , it should do much better than the test
### data sets; and it did do better the second time after we compared the results of each confusion matrix below. 
### Avg_sensitivity = 0.6579416
### Avg_sensitivity = 0.6789907
### Avg_specificity = 0.8387336
### Avg_specificity = 0.8490719