#load the Hmisc package
library(Hmisc) #for importing data
library(dplyr) #for data manipulation (e.g., count)

data <- spss.get("data/nilt25w2.sav", to.data.frame = TRUE)

