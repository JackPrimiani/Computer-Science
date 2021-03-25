library(rpart)

fit = rpart(Species ~ Petal.Length + Petal.Width + Sepal.Length +
              Sepal.Width, method = "class", data=iris, control
            =rpart.control(minsplit=2, cp=0.001))

plot(fit, uniform=TRUE, main="Classification Tree for
Iris Dataset")

text(fit, use.n=TRUE, all=TRUE, cex=.5)