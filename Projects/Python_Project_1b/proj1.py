#Global Constants
NUM_HASHTAGS = 20

#Function declarations

#The function below prints out the opening message when first started
def introMessage():
    print("Welcome to the Hashtag Analyzer")
    print("You will choose a file of hashtags to search for")
    print("Then you will choose a file to search for the hashtags")


#The function below asks the user to enter a file with the hashtags.
#It prompts again if the file does not exist

def hashtagFile():
    opened = False

    while not opened:
        filename = input("Please enter the file with the hashtags you would like to use:")
        try:
            hashtagFile = open(filename, "r")
            opened = True
        except FileNotFoundError:
            print("File doesn't exist")

    hashtagFile.close()
    return filename


#The function below checks to see if a file is empty or not
#Input: filename. Returns true if file is empty

def isEmpty(filename):
    #opens file
    hashtagFile = open(filename, "r")

    #if first line is empty, return true
    #if it is not empty, return false
    temp = hashtagFile.readline()

    hashtagFile.close()

    if temp == "":
        return True
    else:
        return False


#The function below asks the user to enter a file that we want to parse
#It prompts again if the file does not exist
def parsingFile():
    opened = False

    while not opened:
        filename = input("Please enter the file with the hashtags you would like to use:")
        try:
            parseFile = open(filename, "r")
            opened = True
        except FileNotFoundError:
            print("File doesn't exist")

    parseFile.close()
    return filename

#The function will load all hashtag into an array and return that array
#Input: filename and empty hashtag array. Output: array of hashtags
def loadHashtags(filename, hashtagArray):
    #opens up the file
    hashtagFile = open(filename, "r")

    #iterate through each line and add temp as an element
    for i in range(NUM_HASHTAGS):
        temp = hashtagFile.readline()
        hashtagArray.append(temp)

    hashtagFile.close()
    print(f'{NUM_HASHTAGS} hashtags loaded')


#The function below will split the hastag and the actual message into 2 arrays
#input: file name, empty message array, empty hashtag array. No output
def loadMessage(filename, messagesArray, parseHashtagsArray):
    hashtagFile = open(filename, "r")
    