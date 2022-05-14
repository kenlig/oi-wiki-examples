import * as YAML from 'yaml';
import * as fs from 'fs';
interface sol{
    cpp:string;
    python:string;
}
class problem{
    version:number;
    id:string;
    name:string;
    target?:string[];
    solution:sol;
    constructor(){
        try{
            let buffer=fs.readFileSync('./config/config.yml','utf8');
            let config=YAML.parse(buffer);
            this.version=config['version'];
            this.id=config['id'];
            this.name=config['name'];
            this.target=config['target'];
            this.solution=config['solution'];
        }catch(err){
            console.log(err);
        }
    }
    public print(){
        try{
            console.log(this.version);
            console.log(this.id);
            console.log(this.name);
            console.log(this.target);
            console.log(this.solution);
        }catch(err){
            console.log(err);
        }
    }
}
let test:problem;
test=new problem();
test.print();