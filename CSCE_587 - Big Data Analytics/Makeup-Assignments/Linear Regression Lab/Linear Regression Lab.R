x = runif(150, 0, 50)

y = 3.142 + x + rnorm(150)*2.5

plot(y ~ x)

m = lm(y ~ x)

str(m)
print(m) 
par(mfrow=c(2,2))
plot(m)
ypred = predict(m)
par(mfrow=c(1,1))
plot(y,y,type='l', xlab="observed y", ylab="predicted y")
points(y, ypred)

summary(m)
plot(RealEstate)
summary(RealEstate)

r = lm(RealEstate$Price ~ RealEstate$Size)

str(r)

print(r)

par(mfrow=c(2,2))
plot(r)

ypred = predict(r)
par(mfrow=c(1,1))
plot(RealEstate$Price, RealEstate$Price, type="l",
     xlab="Observed y", ylab="Predicted y")
points(RealEstate$Price, ypred)

summary(r)