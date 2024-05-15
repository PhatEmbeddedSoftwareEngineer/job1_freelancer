// Database Paths
var dataFloatPath = 'test/doam';
var dataIntPath = 'test/nhietdo';
var khigas='test/khigas';
var baokhoi = 'test/baokhoi';

// Get a database reference 
const databaseFloat = database.ref(dataFloatPath);
const databaseInt = database.ref(dataIntPath);

const databaseGas = database.ref(khigas);
const databaseKhoi= database.ref(baokhoi);

// Variables to save database current values
var floatReading;
var intReading;

var khigas;
var baokhoi;

// Attach an asynchronous callback to read the data
databaseFloat.on('value', (snapshot) => {
  floatReading = snapshot.val();
  console.log(floatReading);
  document.getElementById("reading-float").innerHTML = floatReading;
}, (errorObject) => {
  console.log('The read failed: ' + errorObject.name);
});

databaseInt.on('value', (snapshot) => {
  intReading = snapshot.val();
  console.log(intReading);
  document.getElementById("reading-int").innerHTML = intReading;
}, (errorObject) => {
  console.log('The read failed: ' + errorObject.name);
});


databaseGas.on('value', (snapshot) => {
  khigas = snapshot.val();
  console.log(khigas);
  document.getElementById("gas").innerHTML = khigas;
}, (errorObject) => {
  console.log('The read failed: ' + errorObject.name);
});


databaseKhoi.on('value', (snapshot) => {
  baokhoi = snapshot.val();
  console.log(baokhoi);
  document.getElementById("baokhoi").innerHTML = baokhoi;
}, (errorObject) => {
  console.log('The read failed: ' + errorObject.name);
});

