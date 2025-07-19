const RulevectorArray=[];
const maxLengthArrays = [];
let n = 1;
const finalArr=[];
const finalLengthArr=[];
const arrayStoringInitialConfig=[];
const arrayStoringmaxLengths = [];
const array = [];
const helpfull =[];
function Findall(){const table4 = [
    {
        name:"Completely Dependent",
        value:[90, 165, 150, 105]
    },
    {
        name:"Partially Dependent",
        value:[30, 45, 75, 120, 135, 180, 210, 225, 86, 89, 101, 106, 149, 154, 166, 169]
    },
    {
        name:"Weakly Dependent",
        value:[53, 58, 83, 92, 163, 172, 197, 202, 54, 57, 99, 108, 147, 156, 198, 201, 23, 43, 77, 113, 142, 178, 212, 232, 27, 39, 78, 114, 141, 177, 216, 228]
    },
    {
        name:"Independent",
        value:[51, 204, 85, 170, 102, 153, 60, 195, 15, 240]
    }
]
const table2a = [
    {
        ClassOfRi: 1,
        Ri: [51, 204, 60, 195],
        ClassOfR_i_next: 1
    },
    {
        ClassOfRi: 1,
        Ri: [85, 90, 165, 170],
        ClassOfR_i_next: 2
    },
    {
        ClassOfRi: 1,
        Ri: [102, 105, 150, 153],
        ClassOfR_i_next: 3
    },
    {
        ClassOfRi: 1,
        Ri: [53, 58, 83, 92, 163, 172, 197, 202],
        ClassOfR_i_next: 4
    },
    {
        ClassOfRi: 1,
        Ri: [54, 57, 99, 108, 147, 156, 198, 201],
        ClassOfR_i_next: 5
    },
    {
        ClassOfRi: 1,
        Ri: [86, 89, 101, 106, 149, 154, 166, 169],
        ClassOfR_i_next: 6
    },
    {
        ClassOfRi: 2,
        Ri: [15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240],
        ClassOfR_i_next: 1
    },
    {
        ClassOfRi: 3,
        Ri: [51, 204, 15, 240],
        ClassOfR_i_next: 1
    },
    {
        ClassOfRi: 3,
        Ri: [85, 105, 150, 170],
        ClassOfR_i_next: 2
    },
    {
        ClassOfRi: 3,
        Ri: [90, 102, 153, 165],
        ClassOfR_i_next: 3
    },
    {
        ClassOfRi: 3,
        Ri: [23, 43, 77, 113, 142, 178, 212, 232],
        ClassOfR_i_next: 4
    },
    {
        ClassOfRi: 3,
        Ri: [27, 39, 78, 114, 141, 177, 216, 228],
        ClassOfR_i_next: 5
    },
    {
        ClassOfRi: 3,
        Ri: [86, 89, 101, 106, 149, 154, 166, 169],
        ClassOfR_i_next: 6
    },
    {
        ClassOfRi: 4,
        Ri: [60, 195],
        ClassOfR_i_next: 1
    },
    {
        ClassOfRi: 4,
        Ri: [90, 165],
        ClassOfR_i_next: 4
    },
    {
        ClassOfRi: 4,
        Ri: [105, 150],
        ClassOfR_i_next: 5
    },
    {
        ClassOfRi: 5,
        Ri: [51, 204],
        ClassOfR_i_next: 1
    },
    {
        ClassOfRi: 5,
        Ri: [85, 170],
        ClassOfR_i_next: 2
    },
    {
        ClassOfRi: 5,
        Ri: [102, 153],
        ClassOfR_i_next: 3
    },
    {
        ClassOfRi: 5,
        Ri: [86, 89, 90, 101, 105, 106,
            149, 150, 154, 165, 166, 169],
        ClassOfR_i_next: 6
    },
    {
        ClassOfRi: 6,
        Ri: [15, 240],
        ClassOfR_i_next: 1
    },
    {
        ClassOfRi: 6,
        Ri: [105, 150],
        ClassOfR_i_next: 4
    },
    {
        ClassOfRi: 6,
        Ri: [90, 165],
        ClassOfR_i_next: 5
    }
]
const table2aForCell0 = [
    {
        RuleForCell0Array:[3, 12],
        ClassOfNextCell:1
    },
    {
        RuleForCell0Array:[5, 10],
        ClassOfNextCell:2
    },
    {
        RuleForCell0Array:[6, 9],
        ClassOfNextCell:3
    }
]
const RulesForCell0 = [5, 6, 9, 10];
const RulesForLastCell = [5, 20, 65, 80];
const RuleVector = [0,0,0,0,0,0,0,0];
function RandomNumberGeneratorForSelectingRuleForCell0_And_LastCell(){
    const randomnumber = Math.floor(Math.random()*RulesForCell0.length);
    return randomnumber;
}
function RandomNumberGenerator(){
    const number = Math.random();
    return number;
}
//Creating sets C_q
let C_Dependence_1_Class_1=[];
let C_Dependence_1_Class_2=[];
let C_Dependence_1_Class_3=[];
let C_Dependence_1_Class_4=[];
let C_Dependence_1_Class_5=[];
let C_Dependence_1_Class_6=[];
let C_Dependence_Partial_Class_1=[];
let C_Dependence_Partial_Class_2=[];
let C_Dependence_Partial_Class_3=[];
let C_Dependence_Partial_Class_4=[];
let C_Dependence_Partial_Class_5=[];
let C_Dependence_Partial_Class_6=[];
let C_Dependence_Weakly_Class_1=[];
let C_Dependence_Weakly_Class_2=[];
let C_Dependence_Weakly_Class_3=[];
let C_Dependence_Weakly_Class_4=[];
let C_Dependence_Weakly_Class_5=[];
let C_Dependence_Weakly_Class_6=[];
let C_Dependence_Independent_Class_1=[];
let C_Dependence_Independent_Class_2=[];
let C_Dependence_Independent_Class_3=[];
let C_Dependence_Independent_Class_4=[];
let C_Dependence_Independent_Class_5=[];
let C_Dependence_Independent_Class_6=[];
for(let i=0;i<table4.length;i++){
    if(table4[i].name=="Completely Dependent"){
        for(var j=0;j<table4[i].value.length;j++){
            for(var k=0;k<table2a.length;k++){
                if(table2a[k].ClassOfRi==1){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_1_Class_1.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==2){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_1_Class_2.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==3){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_1_Class_3.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==4){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_1_Class_4.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==5){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_1_Class_5.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==6){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_1_Class_6.push(table4[i].value[j]);
                        }
                    }
                }
            }
        }
    }
    else if(table4[i].name=="Partially Dependent"){
        for(var j=0;j<table4[i].value.length;j++){
            for(var k=0;k<table2a.length;k++){
                if(table2a[k].ClassOfRi==1){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Partial_Class_1.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==2){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Partial_Class_2.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==3){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Partial_Class_3.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==4){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Partial_Class_4.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==5){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Partial_Class_5.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==6){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Partial_Class_6.push(table4[i].value[j]);
                        }
                    }
                }
            }
        }
    }
    else if(table4[i].name=="Weakly Dependent"){
        for(var j=0;j<table4[i].value.length;j++){
            for(var k=0;k<table2a.length;k++){
                if(table2a[k].ClassOfRi==1){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Weakly_Class_1.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==2){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Weakly_Class_2.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==3){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Weakly_Class_3.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==4){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Weakly_Class_4.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==5){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Weakly_Class_5.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==6){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Weakly_Class_6.push(table4[i].value[j]);
                        }
                    }
                }
            }
        }
    }
    else if(table4[i].name=="Independent"){
        for(var j=0;j<table4[i].value.length;j++){
            for(var k=0;k<table2a.length;k++){
                if(table2a[k].ClassOfRi==1){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Independent_Class_1.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==2){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Independent_Class_2.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==3){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Independent_Class_3.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==4){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Independent_Class_4.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==5){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Independent_Class_5.push(table4[i].value[j]);
                        }
                    }
                }
                else if(table2a[k].ClassOfRi==6){
                    for(var l=0;l<table2a[k].Ri.length;l++){
                        if(table4[i].value[j]==table2a[k].Ri[l]){
                            C_Dependence_Independent_Class_6.push(table4[i].value[j]);
                        }
                    }
                }
            }
        }
    }
}
const RuleForCell0 = RulesForCell0[RandomNumberGeneratorForSelectingRuleForCell0_And_LastCell()];
RuleVector[0]=RuleForCell0;
let ClassForCellFirst = 0;
for(var i=0;i<table2aForCell0.length;i++){
    for(var j=0;j<table2aForCell0[i].RuleForCell0Array.length;j++){
        if(RuleVector[0]==table2aForCell0[i].RuleForCell0Array[j]){
            ClassForCellFirst=table2aForCell0[i].ClassOfNextCell;
        }
    }
}
function RandomnumberGeneratorForArray(array){
    const numberG = Math.floor(Math.random()*array.length);
    return numberG;
}
let ClassForCell1=0;
let help=0;
for(var i=1;i<RuleVector.length-1;i++){
    if(i==1){
        ClassForCell1=ClassForCellFirst;
    }
    else{
        for(let a=0;a<table2a.length;a++){
            if(table2a[a].ClassOfRi==help){
                for(let b=0;b<table2a[a].Ri.length;b++){
                    if(table2a[a].Ri[b]==RuleVector[i-1]){
                        ClassForCell1=table2a[a].ClassOfR_i_next;
                    }
                }
            }
        }
    }
    let Random_Variable_X = RandomNumberGenerator();
    if(Random_Variable_X<0.35){
        if(ClassForCell1==1){
            if(C_Dependence_Partial_Class_1.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_1);
                RuleVector[i]=C_Dependence_Partial_Class_1[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_1);
                RuleVector[i]=C_Dependence_1_Class_1[randomnumber];
            }
            help=1;
        }
        else if(ClassForCell1==2){
            if(C_Dependence_Partial_Class_2.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_2);
                RuleVector[i]=C_Dependence_Partial_Class_2[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_2);
                RuleVector[i]=C_Dependence_1_Class_2[randomnumber];
            }
            help=2;
        }
        else if(ClassForCell1==3){
            if (C_Dependence_Partial_Class_3.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_3);
                RuleVector[i]=C_Dependence_Partial_Class_3[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_3);
                RuleVector[i]=C_Dependence_1_Class_3[randomnumber];
            }
            help=3;
        }
        else if(ClassForCell1==4){
            if(C_Dependence_Partial_Class_4.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_4);
                RuleVector[i]=C_Dependence_Partial_Class_4[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_4);
                RuleVector[i]=C_Dependence_1_Class_4[randomnumber];
            }
            help=4;
        }
        else if(ClassForCell1==5){
            if(C_Dependence_Partial_Class_5.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_5);
                RuleVector[i]=C_Dependence_Partial_Class_5[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_5);
                RuleVector[i]=C_Dependence_1_Class_5[randomnumber];
            }
            help=5;
        }
        else if(ClassForCell1==6){
            if(C_Dependence_Partial_Class_6.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_6);
                RuleVector[i]=C_Dependence_Partial_Class_6[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_6);
                RuleVector[i]=C_Dependence_1_Class_6[randomnumber];
            }
            help=6;
        }
    }
    else if(Random_Variable_X<0.75){
        if(ClassForCell1==1){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_1);
            RuleVector[i]=C_Dependence_1_Class_1[randomnumber];
            help=1;
        }
        else if(ClassForCell1==2){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_2);
            RuleVector[i]=C_Dependence_1_Class_2[randomnumber];
            help=2;
        }
        else if(ClassForCell1==3){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_3);
            RuleVector[i]=C_Dependence_1_Class_3[randomnumber];
            help=3;
        }
        else if(ClassForCell1==4){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_4);
            RuleVector[i]=C_Dependence_1_Class_4[randomnumber];
            help=4;
        }
        else if(ClassForCell1==5){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_5);
            RuleVector[i]=C_Dependence_1_Class_5[randomnumber];
            help=5;
        }
        else if(ClassForCell1==6){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_6);
            RuleVector[i]=C_Dependence_1_Class_6[randomnumber];
            help=6;
        }
    }
    else{
        if(ClassForCell1==1){
            if(C_Dependence_Weakly_Class_1.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_1);
                RuleVector[i]=C_Dependence_Weakly_Class_1[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_1);
                RuleVector[i]=C_Dependence_1_Class_1[randomnumber];
            }
            help=1;
        }
        else if(ClassForCell1==2){
            if(C_Dependence_Weakly_Class_2.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_2);
                RuleVector[i]=C_Dependence_Weakly_Class_2[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_2);
                RuleVector[i]=C_Dependence_1_Class_2[randomnumber];
            }
            help=2;
        }
        else if(ClassForCell1==3){
            if(C_Dependence_Weakly_Class_3.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_3);
                RuleVector[i]=C_Dependence_Weakly_Class_3[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_3);
                RuleVector[i]=C_Dependence_1_Class_3[randomnumber];
            }
            help=3;
        }
        else if(ClassForCell1==4){
            if(C_Dependence_Weakly_Class_4.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_4);
                RuleVector[i]=C_Dependence_Weakly_Class_4[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_4);
                RuleVector[i]=C_Dependence_1_Class_4[randomnumber];
            }
            help=4;
        }
        else if(ClassForCell1==5){
            if(C_Dependence_Weakly_Class_5.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_5);
                RuleVector[i]=C_Dependence_Weakly_Class_5[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_5);
                RuleVector[i]=C_Dependence_1_Class_5[randomnumber];
            }
            help=5;
        }
        else if(ClassForCell1==6){
            if(C_Dependence_Weakly_Class_6.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_6);
                RuleVector[i]=C_Dependence_Weakly_Class_6[randomnumber];
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_6);
                RuleVector[i]=C_Dependence_1_Class_6[randomnumber];
            }
            help=6;
        }
    }
}
const RuleForLastCell = RulesForLastCell[RandomNumberGeneratorForSelectingRuleForCell0_And_LastCell()];
RuleVector[RuleVector.length-1]=RuleForLastCell;
var number = "00000000";
// 01101110
var arrayOfNeighbours = [];
var visitedhelp=[];
var bool = false;
let nextConfig="";
let lengthArray = [];
let length = 0;
let maxlengthArray=[];
let allConfigs=[];
for (let i = 0; i < 8; i++) {
    let binaryString = i.toString(2).padStart(8, '0');
    allConfigs.push(binaryString);
}
let leftconfigs=[];
function endingFunction(){
        bool = true;
}
function findingN(num){
    arrayOfNeighbours=[]
    let leftN='';
    let rightN='';
    let middle='';
    for(var i=0;i<num.length;i++){
        if(i==0){
            leftN='0';
            rightN=num[1];
            middle=num[0];
        }
        else if(i==num.length-1){
            leftN=num[i-1];
            rightN='0';
            middle=num[i];
        }
        else{
            leftN=num[i-1];
            rightN=num[i+1];
            middle=num[i];
        }
        let N = leftN+middle+rightN;
        arrayOfNeighbours.push(N);
    }
    return arrayOfNeighbours;
}
function ApplyRule(RuleVector,array){
    nextConfig="";
    for(var i=0;i<array.length;i++){
        if(RuleVector[i]==90){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==165){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==30){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==150){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==5){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==197){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==80){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==20){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==9){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==78){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==105){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==216){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==6){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==65){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==141){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==89){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==43){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==202){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==10){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==210){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==106){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==101){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==154){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==135){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==166){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==120){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==57){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==149){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==75){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==169){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==232){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==86){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==39){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==53){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==27){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==212){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==156){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==108){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==163){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==147){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==45){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==178){
            if(array[i]=="000"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
        else if(RuleVector[i]==99){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'0'
            }
        }
        else if(RuleVector[i]==225){
            if(array[i]=="000"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="001"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="010"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="011"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="100"){
                nextConfig=nextConfig+'0'
            }
            else if(array[i]=="101"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="110"){
                nextConfig=nextConfig+'1'
            }
            else if(array[i]=="111"){
                nextConfig=nextConfig+'1'
            }
        }
    }
    if(visitedhelp.length != 0){
        for(var i=0;i<visitedhelp.length;i++){
            if(visitedhelp[i]==nextConfig){
                endingFunction();
            }
        }
        visitedhelp.push(nextConfig);
    }
}
function redo(number){visitedhelp.push(number);
arrayStoringInitialConfig.push(number);
for(var i=0;i<(2**8);i++){
   if(i==0){
       var array=findingN(number);
       ApplyRule(RuleVector,array);
       length++;
   }
   else{
        if(bool==true){
            break;
        }
        else{
            var array = findingN(nextConfig);
            ApplyRule(RuleVector,array);
            length++;
        }
   }
}
leftconfigs=[]
lengthArray.push(length);
if(lengthArray.length==1){
    maxlengthArray.push(lengthArray[0]);
}
else{
    maxlengthArray.push(lengthArray[lengthArray.length-1]-lengthArray[lengthArray.length-2]);
}
visitedhelp.pop();
bool=false;
function findingLeftConf(){
    for(var i=0;i<allConfigs.length;i++){
        var notincluded=false;
        for(var j=0;j<visitedhelp.length;j++){
            if(allConfigs[i]==visitedhelp[j]){
                notincluded=false;
                break;
            }
            else{
                notincluded=true;
            }
        }
        if(notincluded==true){
            leftconfigs.push(allConfigs[i]);
        }
    }
}
findingLeftConf();
}
redo(number);
while(leftconfigs.length != 0){
    redo(leftconfigs[0]);
}
let maxlen =0;
for(var i=0;i<maxlengthArray.length;i++){
    if(maxlengthArray[i]>maxlen){
        maxlen=maxlengthArray[i];
    }
}
arrayStoringmaxLengths.push(maxlen);
RulevectorArray.push(RuleVector);
maxLengthArrays.push(maxlen);
for(var i=0;i<arrayStoringInitialConfig.length;i++){
    if(maxlengthArray[i]==maxlen){
        array.push(arrayStoringInitialConfig[i]);
    }
}
}
while(n<5000){
    Findall();
    n++;
}
for(var i=0;i<maxLengthArrays.length;i++){
    if(maxLengthArrays[i]>200){
        finalLengthArr.push(maxLengthArrays[i]);
        finalArr.push(RulevectorArray[i]);
    }
}
for(var i=0;i<arrayStoringmaxLengths.length;i++){
    if(arrayStoringmaxLengths[i]>200){
        helpfull.push(array[i]);
    }
}
