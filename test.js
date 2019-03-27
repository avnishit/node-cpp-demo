`use strict`
let assert = require('assert');
let { data : add } = require('./app');
describe('Test Add Function with', function() {
  describe('int inputs', function() {
    it('should add 7 and 9', function() {
      assert.equal(add(7,9),79);
    });
  });
});
