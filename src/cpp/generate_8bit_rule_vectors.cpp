const table4 = [
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
            // console.log(table4[i].value[j]);
            for(var k=0;k<table2a.length;k++){
                if(table2a[k].ClassOfRi==1){
                  
                    // console.log(table2a[k].ClassOfRi);
                    
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
console.log(RuleVector[0]);

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
console.log(ClassForCellFirst);
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
    console.log("help"+help);
    console.log(ClassForCell1);
    let Random_Variable_X = RandomNumberGenerator();
    console.log(Random_Variable_X);
    if(Random_Variable_X<0.35){
        if(ClassForCell1==1){
            if(C_Dependence_Partial_Class_1.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_1);
                RuleVector[i]=C_Dependence_Partial_Class_1[randomnumber];
                console.log("PartialClass=1 "+C_Dependence_Partial_Class_1)
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_1);
                RuleVector[i]=C_Dependence_1_Class_1[randomnumber];
                console.log(C_Dependence_1_Class_1)
            }
            help=1;
        }
        else if(ClassForCell1==2){
            if(C_Dependence_Partial_Class_2.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_2);
                RuleVector[i]=C_Dependence_Partial_Class_2[randomnumber];
                console.log("PartialClass2 "+C_Dependence_Partial_Class_2)
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_2);
                RuleVector[i]=C_Dependence_1_Class_2[randomnumber];
                console.log(C_Dependence_1_Class_2);
            }
            help=2;
        }
        else if(ClassForCell1==3){
            if (C_Dependence_Partial_Class_3.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_3);
                RuleVector[i]=C_Dependence_Partial_Class_3[randomnumber];
                console.log("PartialClass3 "+C_Dependence_Partial_Class_3);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_3);
                RuleVector[i]=C_Dependence_1_Class_3[randomnumber];
                console.log(C_Dependence_1_Class_3);
            }
            help=3;
        }
        else if(ClassForCell1==4){
            if(C_Dependence_Partial_Class_4.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_4);
                RuleVector[i]=C_Dependence_Partial_Class_4[randomnumber];
                console.log("PartialClass4 "+C_Dependence_Partial_Class_4);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_4);
                RuleVector[i]=C_Dependence_1_Class_4[randomnumber];
                console.log(C_Dependence_1_Class_4);
            }
            help=4;
        }
        else if(ClassForCell1==5){
            if(C_Dependence_Partial_Class_5.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_5);
                RuleVector[i]=C_Dependence_Partial_Class_5[randomnumber];
                console.log("PartialClass5 "+C_Dependence_Partial_Class_5);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_5);
                RuleVector[i]=C_Dependence_1_Class_5[randomnumber];
                console.log(C_Dependence_1_Class_5);
            }
            help=5;
        }
        else if(ClassForCell1==6){
            if(C_Dependence_Partial_Class_6.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Partial_Class_6);
                RuleVector[i]=C_Dependence_Partial_Class_6[randomnumber];
                console.log("PartialClass6 "+C_Dependence_Partial_Class_6);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_6);
                RuleVector[i]=C_Dependence_1_Class_6[randomnumber];
                console.log(C_Dependence_1_Class_6);
            }
            help=6;
        }
    }
    else if(Random_Variable_X<0.75){
        if(ClassForCell1==1){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_1);
            RuleVector[i]=C_Dependence_1_Class_1[randomnumber];
            help=1;
            console.log("FullyClass1 "+C_Dependence_1_Class_1);
        }
        else if(ClassForCell1==2){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_2);
            RuleVector[i]=C_Dependence_1_Class_2[randomnumber];
            help=2;
            console.log("FullyClass2 "+C_Dependence_1_Class_2);
        }
        else if(ClassForCell1==3){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_3);
            RuleVector[i]=C_Dependence_1_Class_3[randomnumber];
            help=3;
            console.log("FullyClass3 "+C_Dependence_1_Class_3);
        }
        else if(ClassForCell1==4){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_4);
            RuleVector[i]=C_Dependence_1_Class_4[randomnumber];
            help=4;
            console.log("FullyClass4 "+C_Dependence_1_Class_4);
        }
        else if(ClassForCell1==5){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_5);
            RuleVector[i]=C_Dependence_1_Class_5[randomnumber];
            help=5;
            console.log("FullyClass5 "+C_Dependence_1_Class_5);
        }
        else if(ClassForCell1==6){
            const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_6);
            RuleVector[i]=C_Dependence_1_Class_6[randomnumber];
            help=6;
            console.log("FullyClass6 "+C_Dependence_1_Class_6);
        }
    }
    else{
        
        if(ClassForCell1==1){
            if(C_Dependence_Weakly_Class_1.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_1);
                RuleVector[i]=C_Dependence_Weakly_Class_1[randomnumber];
                console.log("WeaklyClass1 "+C_Dependence_Weakly_Class_1);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_1);
                RuleVector[i]=C_Dependence_1_Class_1[randomnumber];
                console.log(C_Dependence_1_Class_1);
            }
            help=1;
        }
        else if(ClassForCell1==2){
            if(C_Dependence_Weakly_Class_2.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_2);
                RuleVector[i]=C_Dependence_Weakly_Class_2[randomnumber];
                console.log("WeaklyClass2 "+C_Dependence_Weakly_Class_2);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_2);
                RuleVector[i]=C_Dependence_1_Class_2[randomnumber];
                console.log(C_Dependence_1_Class_2);
            }
            help=2;
        }
        else if(ClassForCell1==3){
            if(C_Dependence_Weakly_Class_3.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_3);
                RuleVector[i]=C_Dependence_Weakly_Class_3[randomnumber];
                console.log("WeaklyClass3 "+C_Dependence_Weakly_Class_3);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_3);
                RuleVector[i]=C_Dependence_1_Class_3[randomnumber];
                console.log(C_Dependence_1_Class_3);
            }
            help=3;
        }
        else if(ClassForCell1==4){
            if(C_Dependence_Weakly_Class_4.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_4);
                RuleVector[i]=C_Dependence_Weakly_Class_4[randomnumber];
                console.log("WeaklyClass4 "+C_Dependence_Weakly_Class_4);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_4);
                RuleVector[i]=C_Dependence_1_Class_4[randomnumber];
                console.log(C_Dependence_1_Class_4);
            }
            help=4;
        }
        else if(ClassForCell1==5){
            if(C_Dependence_Weakly_Class_5.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_5);
                RuleVector[i]=C_Dependence_Weakly_Class_5[randomnumber];
                console.log("WeaklyClass5 "+C_Dependence_Weakly_Class_5);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_5);
                RuleVector[i]=C_Dependence_1_Class_5[randomnumber];
                console.log(C_Dependence_1_Class_5);
            }
            help=5;
        }
        else if(ClassForCell1==6){
            if(C_Dependence_Weakly_Class_6.length !== 0){
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_Weakly_Class_6);
                RuleVector[i]=C_Dependence_Weakly_Class_6[randomnumber];
                console.log("WeaklyClass6 "+C_Dependence_Weakly_Class_6);
            }
            else{
                const randomnumber = RandomnumberGeneratorForArray(C_Dependence_1_Class_6);
                RuleVector[i]=C_Dependence_1_Class_6[randomnumber];
                console.log(C_Dependence_1_Class_6);
            }
            help=6;
        }
    }
}
const RuleForLastCell = RulesForLastCell[RandomNumberGeneratorForSelectingRuleForCell0_And_LastCell()];
RuleVector[RuleVector.length-1]=RuleForLastCell;