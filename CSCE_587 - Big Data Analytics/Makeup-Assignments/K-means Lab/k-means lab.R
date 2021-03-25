# Jack Primiani
# k-means lab

# input data: https://cse.sc.edu/~rose/587/CSV/state_income.csv
# 1) use wget to copy the dataset to the vm
# 2) use GUI import from Text (base) to import state_income.csv
#Sort data

state_income <- read.csv("https://cse.sc.edu/~rose/587/CSV/state_income.csv", header = FALSE)
View(state_income)


tmp = sort(state_income$V2)
#Visualize data
plot(tmp)
# create 4 clusters
kmeans=kmeans(tmp,4,15)
#Visualize the cluster centers
points(kmeans$centers, col = 1:4, pch=20)
# Lets start with 2 dimensions: visualize data

iris <- read.csv("iris.csv", header = FALSE)
View(iris)

plot(iris[,1:2])
# create 4 clusters
kmeans=kmeans(iris[,1:2],4,15)
#Visualize the cluster centers
points(kmeans$centers, col = 1:4, pch=20)
# Visualize clusters
plot(iris[,1:2], col=kmeans$cluster)
# Visualize the cluster centers
points(kmeans$centers, col = 1:4, pch=20)
withinSumSqrs = numeric(20)
for (k in 1:20) withinSumSqrs[k] = sum(kmeans(iris[,1:2],centers=k)$withinss)
#Visualize within cluster sum of square
plot(1:20, withinSumSqrs, type="b", xlab="# Clusters", ylab="Within sum of square") 
# Lets consider 3 dimensions: visualize data
plot(iris[,1:3])
# create 4 clusters
kmeans=kmeans(iris[,1:3],4,15)
# Visualize the clusters
plot(iris[,1:3], col=kmeans$cluster)
# Examine a single 2D projection
plot(iris[,1:2], col=kmeans$cluster)
#Visualize the cluster centers
points(kmeans$centers, col = 1:4, pch=20)
# Examine another single 2D projection
plot(iris[,c(1,3)], col=kmeans$cluster)
#Visualize the cluster centers
points(kmeans$centers[,c(1,3)], col = 1:4, pch=20)
withinSumSqrs = numeric(20)
for (k in 1:20) withinSumSqrs[k] = sum(kmeans(iris[,1:3],centers=k)$withinss)
plot(1:20, withinSumSqrs, type="b", xlab="# Clusters", ylab="Within sum of square") 
# Finally consider 4 dimensions: visualize data
plot(iris[,1:4])
# create 4 clusters
kmeans=kmeans(iris[,1:4],4,15)
# Visualize the clusters
plot(iris[,1:4], col=kmeans$cluster)
summary(iris[,1:4])
myShift = function(x) { x - min(x, na.rm=TRUE)}
myShift(iris[,3])
as.data.frame(lapply(iris[,1:4], myShift))
summary(as.data.frame(lapply(iris[,1:4], myShift)))
myScale = function(x) { max(x,na.rm=TRUE) - min(x,na.rm=TRUE)}
myScale(iris[,3])
as.data.frame(lapply(iris[,1:4], myScale))
myNorm = function(x) { myShift(x)/myScale(x) }
myNorm(iris[,3])
tmp = as.data.frame(lapply(iris[,1:4], myNorm))
summary(as.data.frame(lapply(iris[,1:4], myNorm)))
plot(tmp[,1:4])
for (k in 1:20) withinSumSqrs[k] =
sum(kmeans(tmp[,1:4],centers=k)$withinss)
plot(1:20, withinSumSqrs, type="b", xlab="# Clusters", ylab="Within sum of
square")