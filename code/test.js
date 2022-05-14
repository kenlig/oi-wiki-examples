"use strict";
exports.__esModule = true;
var YAML = require("yaml");
var fs = require("fs");
var problem = /** @class */ (function () {
    function problem() {
        try {
            var buffer = fs.readFileSync('./config/config.yml', 'utf8');
            var config = YAML.parse(buffer);
            this.version = config['version'];
            this.id = config['id'];
            this.name = config['name'];
            this.target = config['target'];
            this.solution = config['solution'];
        }
        catch (err) {
            console.log(err);
        }
    }
    problem.prototype.print = function () {
        try {
            console.log(this.version);
            console.log(this.id);
            console.log(this.name);
            console.log(this.target);
            console.log(this.solution);
        }
        catch (err) {
            console.log(err);
        }
    };
    return problem;
}());
var test;
test = new problem();
test.print();
