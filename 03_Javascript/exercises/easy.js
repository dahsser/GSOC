let socialNetwork = {
  name: "Zuckerber",
  created : "2020",
  comments:[
    {name:"Pedro", comment:"Hola amigutio zuck"},
    {name:"Dahsser", comment:"Uno mas uno es 2"},
    {name:"John", comment:":v"},
    {name:"Julian", comment:"Viva windows!"},
  ],
  dumpObject(){
    console.log("Name:",this.name);
    console.log("Created:",this.created);
    for(let i in this.comments){
      console.log("\t*",this.comments[i].name,"says:",this.comments[i].comment);
    }
  }
}
socialNetwork.dumpObject();
