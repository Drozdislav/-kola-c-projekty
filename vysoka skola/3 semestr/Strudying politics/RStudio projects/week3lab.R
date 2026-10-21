
# Installing and loading packages -----------------------------------------
install.packages("fivethirtyeight")
library(fivethirtyeight)
str(bechdel)

bechdel$title
head(bechdel$title)
table(bechdel$clean_test)
install.packages()
library(dplyr)
count(bechdel, test, clean_test, binary)

pass <- mean(bechdel$domgross_2013[bechdel$binary == "PASS"], na.rm = TRUE)
fail <- mean(bechdel$domgross_2013[bechdel$binary == "FAIL"], na.rm = TRUE)


# Indexing ----------------------------------------------------------------

quick <- c(45,68,21,77,109)
quick[1]
quick[1:3] #first three

bechdel$title[]
bechdel[,3]


# subseting ---------------------------------------------------------------

pass_bechdel <- subset(bechdel, binary == "PASS") #shows only where pass
pass_bechdel_brackets <- bechdel[bechdel$budget > 1000000,]


# importing data ----------------------------------------------------------

install.packages("Hmisc")
library(Hmisc)

data <- spss.get("data/nilt25w2.sav",use.value.labels = T)

str(data, list.len = 5)

head(data[, 1:10])
head(data[, 1:10], n = 10)
head(data$BEHONLN)
