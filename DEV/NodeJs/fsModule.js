// to create a new file in the current directory
// type nul > filename.js

// CHALLENGE:- 
/*
    1: Create a folder 
    2: Create a file in it named bio.txt and data into it.
    3: Add more data into the file at the end of the existing data.
    4: Read the data without getting the buffer data at first.
    file encoding
    5: Rename the file name to mybio.txt
    6: now delete both the file and the folder?

*/


// need to require the file system module
const fs = require('fs');

// to create a folder we use mkdir
fs.mkdir('./challengeFolder', (err) => {
    if(err) throw err;
});

// creating a file in it
fs.writeFileSync('challengeFolder/bio.txt', 'Here is added data 1st');

// add more data into the file at the end of the existing data
fs.appendFileSync('./challengeFolder/bio.txt', '\n2nd line of data added here');

// read the data
const fileData = fs.readFileSync('./challengeFolder/bio.txt', 'utf8');
console.log(fileData);

// rename the file to mybio.txt
fs.renameSync('./challengeFolder/bio.txt', './challengeFolder/mybio.txt');

// delete the file and the folder
fs.rmSync('./challengeFolder/mybio.txt');
fs.rmdirSync('./challengeFolder');