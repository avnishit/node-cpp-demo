
//index.js
const testAddon = require('./build/Release/testaddon.node');
console.log('testaddon:',testAddon.data(2,3));
module.exports = testAddon;
