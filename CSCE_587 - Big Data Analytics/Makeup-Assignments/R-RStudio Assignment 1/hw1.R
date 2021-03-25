#Jack Primiani
#September 8th, 2020
#CSCE 587

# import iris data into R
iris <- read.csv("iris.csv", header = FALSE)
View(iris)

# find min and max values for V1
min(iris$V1)
[1] 4.3
max(iris$V1)
[1] 7.9

# place V1 into a vector
v1 = c(iris$V1)
View(v1)

# setup vector for setosa and transfer data from v1
sertosa = c(1:50)
for(i in 1:50){ sertosa[i] = v1[i]}
View(sertosa)
setosa = sertosa
rm(sertosa)

# plot setosa
hist(setosa, col="red", xlim=c(4,8))
hist(setosa, col="red", xlim=c(4, 8), breaks=seq(4, 8, 0.2)) 
# allow for 3 plots
par(mfrow=c(1,3)) 

# setup vector for veriscolor and virginica
for(i in 51:100){ virginica[i-50] = v1[i]}
View(virginica)
virginica = c(1:50)
View(virginica)
for(i in 51:100){ virginica[i-50] = v1[i]}
View(virginica)
Veriscolor = c(1:50)
for(i in 101:150){ Veriscolor[i-100] = v1[i]}
veriscolor = Veriscolor

# plot all three histograms on plot space
par(mfrow=c(1,3))
plotSet <-hist(setosa, col="blue", xlim=c(4, 8), ylim=c(0,14), breaks=seq(4, 8, 0.2)) 
plotVer <- hist(veriscolor, col="yellow", xlim=c(4, 8), ylim=c(0,14), breaks=seq(4, 8, 0.2)) 
plotVir <- hist(virginica, col="red", xlim=c(4, 8), ylim=c(0,14), breaks=seq(4, 8, 0.2))

#setup for V2 using which statements
v2Setosa <- iris$V2[which(iris$V5 %in% "Iris-setosa")]
v2Veriscolor <- iris$V2[which(iris$V5 %in% "Iris-versicolor")]
v2Virginica <- iris$V2[which(iris$V5 %in% "Iris-virginica")]
# min and max values V2
min(v2)
[1] 2
max(v2)
[1] 4.4
# plot space for 3
par(mfrow=c(1,3))
# initial histograms for each
hist(v2Setosa, col="blue", xlim=c(2, 5), breaks=seq(2, 5, 0.2)) 
hist(v2Veriscolor, col="yellow", xlim=c(2, 5), breaks=seq(2, 5, 0.2)) 
hist(v2Virginica, col="red", xlim=c(2, 5), breaks=seq(2, 5, 0.2)) 
#setup 3 3 plots
par(mfrow=c(1,3))
#plots for V2 
hist(v2Veriscolor, col="yellow", xlim=c(2, 5), ylim=c(0,16), breaks=seq(2, 8, 0.2)) 
hist(v2Setosa, col="blue", xlim=c(2, 5), ylim=c(0,16), breaks=seq(2, 8, 0.2)) 
hist(v2Virginica, col="red", xlim=c(2, 5), ylim=c(0,16), breaks=seq(2, 8, 0.2)) 

# setup f/ V3
min(v3)
[1] 1
max(v3)
[1] 6.9
v3Setosa <- iris$V3[which(iris$V5 %in% "Iris-setosa")]
v3Veriscolor <- iris$V3[which(iris$V5 %in% "Iris-versicolor")]
v3Virginica <- iris$V3[which(iris$V5 %in% "Iris-virginica")]
# 3 plot space
par(mfrow=c(1,3))
# initial plots
hist(v3Setosa, col="blue", xlim=c(1, 7), breaks=seq(1, 7, 0.2)) 
hist(v3Veriscolor, col="yellow", xlim=c(1, 7), breaks=seq(1, 7, 0.2)) 
hist(v3Virginica, col="red", xlim=c(1, 7), breaks=seq(1, 7, 0.2)) 
# plots with Y set
par(mfrow=c(1,3))
hist(v3Setosa, col="blue", xlim=c(1, 7), ylim=c(0,22), breaks=seq(1, 7, 0.2)) 
hist(v3Veriscolor, col="yellow", xlim=c(1, 7), ylim=c(0,26), breaks=seq(1, 7, 0.2)) 
hist(v3Virginica, col="red", xlim=c(1, 7), ylim=c(0,26), breaks=seq(1, 7, 0.2)) 

# V4 setup
v4Setosa <- iris$V4[which(iris$V5 %in% "Iris-setosa")]
v4Veriscolor <- iris$V4[which(iris$V5 %in% "Iris-versicolor")]
v4Virginica <- iris$V4[which(iris$V5 %in% "Iris-virginica")]
min(v4)
[1] 0.1
max(v4)
[1] 2.5
#initial histogram setup
hist(v4Setosa, col="blue", xlim=c(0, 3), breaks=seq(0, 3, 0.2)) 
hist(v4Veriscolor, col="yellow", xlim=c(0, 3), breaks=seq(0, 3, 0.2)) 
hist(v4Virginica, col="red", xlim=c(0, 3), breaks=seq(0, 3, 0.2)) 

# setup w/ modified Y axis
par(mfrow=c(1,3))
hist(v4Setosa, col="blue", xlim=c(0, 3), ylim=c(0,35), breaks=seq(0, 3, 0.2)) 
hist(v4Veriscolor, col="yellow", xlim=c(0, 3), ylim=c(0,35), breaks=seq(0, 3, 0.2)) 
hist(v4Virginica, col="red", xlim=c(0, 3), ylim=c(0,35), breaks=seq(0, 3, 0.2)) 