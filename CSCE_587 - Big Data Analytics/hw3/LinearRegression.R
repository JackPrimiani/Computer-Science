# Jack Primiani
# October 14th, 2020
# CSCE 587 - Linear Regression HW

#Variables for interpolated and DecimalDate
x = MaunaLoa[,3]
y = MaunaLoa[,5]

#1.
#a. Plot the column labelled 'interpolated' (Y) against the column labelled 'DecimalDate' (X).
plot(y ~ x)

#b. Try fitting these two columns with a linear model lm(). Hint: You might want to review the linear
#   regression lab
m = lm(y ~ x)
print(m)

#c. As in the linear regression lab, visualize the model with the commands, where m is the variable you used
#   to hold the model:
par(mfrow=c(2,2))
plot(m)

#d. Explain the top left figure. What does this tell us about the fit of our model?

# The residuals vs fitted graph shows us that y and x do not correspond and can't be used
# to determine on how each other should behave.

#e. Visualize the predicted and observed y values similar to what we did in slide 6 of the
#   linear regression lab

ypred = predict(m)
plot(y,y,type='l', xlab="observed y", ylab="predicted y")
points(y, ypred)

#f.Looking at the plot from 1.a, explain whether this data appears to be i.i.d. Justify your answer.

# I believe this data is not i.i.d. since it follows a linear regression. The data is not independent or identically distributed. 

#2.
#STA
a = icu[-c(1),2]
#AGE
b = icu[-c(1),3]
#SYS
c = icu[-c(1),11]

#a. Plot column 2 'STA' (Y) versus column 3 'AGE' (X). Save this plot to a pdf file.
plot(a ~ b)

#b. Plot column 2 'STA' (Y) against column 11 'SYS' (X). Save this plot to a pdf file.
plot(a ~ c)

library("MASS")

#solution to non-numeric error
a <- as.numeric(as.character(a))
b <- as.numeric(as.character(b))
c <- as.numeric(as.character(c))

#c. Try fitting column 2 versus column 3 with a logistic model glm().
glm.out01 = glm(a ~ b, family=binomial(logit), data=icu)
summary(glm.out01)

#d. Now try fitting column 2 versus columns 3 and 11 with the logistic model glm(). 
glm.out02 = glm(a ~ b+c, family=binomial(logit), data=icu)
summary(glm.out02)

#e. . Compare the models from step c with that of step d using the function summary().
#Coefficients:
#            Estimate Std. Error z value Pr(>|z|)    
#  (Intercept) -3.05851    0.69608  -4.394 1.11e-05 ***
#  b            0.02754    0.01056   2.607  0.00913 ** 
#Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1

#f.Compare the estimated coefficients with each other from step d. 
#ValueAB:   0.02754
#ValueABC:  0.028407

#Coefficients:
#           Estimate Std. Error z value Pr(>|z|)   
# (Intercept)  -0.962471   1.000272  -0.962  0.33594   
#  b            0.028407   0.010774   2.637  0.00838 **
#  c           -0.016831   0.005859  -2.873  0.00407 **
#Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
