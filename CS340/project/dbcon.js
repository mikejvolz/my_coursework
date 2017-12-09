var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit : 10,
  host            : 'classmysql.engr.oregonstate.edu',
  user            : 'cs340_volzm',
  password        : 'xxxx',
  database        : 'cs340_volzm'
});

module.exports.pool = pool;
