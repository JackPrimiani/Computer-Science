traindata <- Bayes[1:14,]

testdata <- Bayes[15,]

Pplay <- table(traindata$Play)
Pplay <- Pplay/sum(Pplay)

sunny <- table(traindata[,c("Play", "Sunny")])
sunny <- sunny/rowSums(sunny)

hot <- table(traindata[,c("Play", "Hot")])
hot <- hot/rowSums(hot)

windy <- table(traindata[,c("Play", "Windy")])
windy <- windy/rowSums(windy)

Pyes <- sunny["Yes","Yes"] * hot["Yes","No"] * windy["Yes","Yes"]
Pno <- sunny["No","Yes"] * hot["No","No"] * windy["No","Yes"]

Max(Pyes, Pno)

install.packages("e1071")

library(e1071)

m <- naiveBayes(traindata[,1:3], traindata[,4])

predict(m,testdata[,1:3])

m <- naiveBayes(iris[,1:4], iris[,5])
table(predict(m, iris[,1:4]), iris[,5])