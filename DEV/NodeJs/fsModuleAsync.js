// take a task, wait for it to finish, then return - synchronous
// take a task, while it's still waiting, take other tasks also, if it's done, then return - asynchronous
const fs = require('fs');

fs.writeFile('newFile.txt', 'Hey hello from asynchronous', (err) => {
    if(err) throw err;
    else
        console.log('File written successfully');
});

// to append data
fs.appendFile('newFile.txt', '\nHere is the appended data', (err) => {
    if(err) throw err;
    else console.log('Data appended successfully');
})

// to read the data
fs.readFile('newFile.txt', 'utf8', (err, data) => {
    if(err) throw err;
    else console.log(data);
});


// CRUD Operations using Asynchronous
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

fs.mkdir('./Challenge', (err) => {
    if(err) throw err;
    else console.log('Folder created successfully');
});

fs.writeFile('./Challenge/chalFile.txt', 'Here goes some dummy data', (err) => {
    if(err) throw err;
    else console.log('File created successfully');
})

fs.appendFile('./Challenge/chalFile.txt', '\nAppended another data', (err) => {
    if(err) throw err;
    else console.log('Data appended successfully');
})

const fileData = fs.readFile('./Challenge/chalFile.txt', 'utf8', (err, data) => {
    if(err) throw err;
    else console.log(data);
})

fs.rename('./Challenge/chalFile.txt', './Challenge/newChalFile.txt', (err) => {
    if(err) throw err;
    else console.log('File renamed successfully');
})

fs.rm('./Challenge/newChalFile.txt', (err) => {
    if(err) throw err;
    else console.log('File removed successfully');
})

fs.rmdir('./Challenge', (err) => {
    if(err) throw err;
    else console.log('Folder removed successfully');
})