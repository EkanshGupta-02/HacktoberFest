# importing the required modules
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords

text = "This is an example of showing off stop words removal"
stop_words = set(stopwords.words("english"))
words = word_tokenize(text)


filtered_word = []

for w in words:
    if w not in stop_words:
        filtered_word.append(w)
    
print("Initial Token texts: ",words)
print("Final Stop word removed texts: ",filtered_word)