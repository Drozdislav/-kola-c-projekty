install.packages("fivethirtyeight")
library(fivethirtyeight)


install.packages("Hmisc")
library(Hmisc)

data <- spss.get("data/nilt25w2.sav",use.value.labels = T)

class(data$RAGECAT) #i would say its oridinal

age_count <- table(data$RAGECAT)

median(age_count) #i dont have an idea how to analyze this

barplot(age_count, main = "Age Range of Respondents")
pie(age_count, main = "Age Range of Respondents")

#in case that the number of respondets corelates to real age spread across NI, then it is okay. the data itself from the purely mathematical pov are more or less okay
#the age of respondents is really important. it could show how people who have lived through different times might respond differently to same questions, or it may show some generational differences
