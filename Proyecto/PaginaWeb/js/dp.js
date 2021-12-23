var car1 = document.getElementById('carro1');
var car2 = document.getElementById('carro2');
var car3 = document.getElementById('carro3');
var car4 = document.getElementById('carro4');
var car5 = document.getElementById('carro5');
var car6 = document.getElementById('carro6');
var car7 = document.getElementById('carro7');
var car8 = document.getElementById('carro8');
var firstt = document.getElementById('first');
var secondd = document.getElementById('second');
var upp = document.getElementById('up');
var downn = document.getElementById('down');
var maxi = document.getElementById('max');
var llamadas = 0;
car1.style.position = 'relative';
car2.style.position = 'relative';
car3.style.position = 'relative';
car4.style.position = 'relative';
car5.style.position = 'relative';
car6.style.position = 'relative';
car7.style.position = 'relative';
car8.style.position = 'relative';
var a = [[0,0,0],[0,0,0]];
var t = [[0,0,0],[0,0,0]];
var e = [0,0];
var x = [0,0];

//Controlar el carro 1
var x_car1 = 0;
var y_car1 = 0;
//Controlar el carro 2
var x_car2 = 0;
var y_car2 = 0;
//Controlar el carro 3
var x_car3 = 0;
var y_car3 = 0;
//Controlar el carro 4
var x_car4 = 0;
var y_car4 = 0;
//Controlar el carro 5
var x_car5 = 0;
var y_car5 = 0;
//Controlar el carro 6
var x_car6 = 0;
var y_car6 = 0;
//Controlar el carro 7
var x_car7 = 0;
var y_car7 = 0;
//Controlar el carro 8
var x_car8 = 0;
var y_car8 = 0;


//Click de prueba
document.getElementById('demo').addEventListener('click', demoSolution);
document.getElementById('aplicar').addEventListener('click', displaySolution);
//car8.addEventListener('click', bruteSolution);

//Mover los carros
function moveCar1(x1, y1){
    x_car1 = x_car1 + x1;
    car1.style.left = x_car1 + "%";

    y_car1 = y_car1 + y1;
    car1.style.top = y_car1 + "%"; 
}
function moveCar2(x1, y1){
    x_car2 = x_car2 + x1;
    car2.style.left = x_car2 + "%";
    y_car2 = y_car2 + y1;
    car2.style.top = y_car2 + "%"; 
}
function moveCar3(x1, y1){
    x_car3 = x_car3 + x1;
    car3.style.left = x_car3 + "%";
    y_car3 = y_car3 + y1;
    car3.style.top = y_car3 + "%"; 
}
function moveCar4(x1, y1){
    x_car4 = x_car4 + x1;
    car4.style.left = x_car4 + "%";
    y_car4 = y_car4 + y1;
    car4.style.top = y_car4 + "%"; 
}
function moveCar5(x1, y1){
    x_car5 = x_car5 + x1;
    car5.style.left = x_car5 + "%";

    y_car5 = y_car5 + y1;
    car5.style.top = y_car5 + "%"; 
}
function moveCar6(x1, y1){
    x_car6 = x_car6 + x1;
    car6.style.left = x_car6 + "%";
    y_car6 = y_car6 + y1;
    car6.style.top = y_car6 + "%"; 
}
function moveCar7(x1, y1){
    x_car7 = x_car7 + x1;
    car7.style.left = x_car7 + "%";
    y_car7 = y_car7 + y1;
    car7.style.top = y_car7 + "%"; 
}
function moveCar8(x1, y1){
    x_car8 = x_car8 + x1;
    car8.style.left = x_car8 + "%";
    y_car8 = y_car8 + y1;
    car8.style.top = y_car8 + "%"; 
}

function returnToStart(car){
    if(car == 1){
        car1.style.left = 0 + "%";
        car1.style.top = 0 + "%";
    }
    else if(car == 2){
        car2.style.left = 0 + "%";
        car2.style.top = 0 + "%";
    }
    else if(car == 3){
        car3.style.left = 0 + "%";
        car3.style.top = 0 + "%";
    }
    else if(car == 4){
        car4.style.left = 0 + "%";
        car4.style.top = 0 + "%";
    }
    else if(car == 5){
        car5.style.left = 0 + "%";
        car5.style.top = 0 + "%";
    }
    else if(car == 6){
        car6.style.left = 0 + "%";
        car6.style.top = 0 + "%";
    }
    else if(car == 7){
        car7.style.left = 0 + "%";
        car7.style.top = 0 + "%";
    }
    else if(car == 8){
        car8.style.left = 0 + "%";
        car8.style.top = 0 + "%";
    }
}
function abs(x){return (x < 0) ? -1*x : x;}

//Sleep para que se vea animado
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}
//Animar los carros
async function animateCar(x1, y1, ncar) {
    for (let i = 0; i < 20; i++) {
        if(ncar == 1){
            moveCar1(x1, y1);
        }
        else if(ncar == 2){
            moveCar2(x1, y1);
        }
        else if(ncar == 3){
            moveCar3(x1, y1);
        }
        else if(ncar == 4){
            moveCar4(x1, y1);
        }
        else if(ncar == 5){
            moveCar5(x1, y1);
        }
        else if(ncar == 6){
            moveCar6(x1, y1);
        }
        else if(ncar == 7){
            moveCar7(x1, y1);
        }
        else if(ncar == 8){
            moveCar8(x1, y1);
        }
        await sleep(100);
    }
}
function bringCar(x, y){
    if(x_car2 == 0){
        y = (y-25);
        car2.style.left = x + "%";
        car2.style.top = y + "%";
        x_car2 = x;
        y_car2 = y;
        return 2;
    }
    else if(x_car3 == 0){
        y = (y-25);
        car3.style.left = x + "%";
        car3.style.top = y + "%";
        x_car3 = x;
        y_car3 = y;
        return 3;
    }
    else if(x_car4 == 0){
        car4.style.left = x + "%";
        car4.style.top = y + "%";
        x_car4 = x;
        y_car4 = y;
        return 4;
    }
    else if(x_car6 == 0){
        car6.style.left = x + "%";
        car6.style.top = y + "%";
        x_car6 = x;
        y_car6 = y;
        return 6;
    }
    else if(x_car7 == 0){
        car7.style.left = x + "%";
        car7.style.top = y + "%";
        x_car7 = x;
        y_car7 = y;
        return 7;
    }
    else if(x_car8 == 0){
        car8.style.left = x + "%";
        car8.style.top = y + "%";
        x_car8 = x;
        y_car8 = y;
        return 8;
    }
}
function getXcar(car){
    if(car == 1){
        return x_car1;
    }
    if(car == 2){
        return x_car2;
    }
    if(car == 3){
        return x_car3;
    }
    if(car == 4){
        return x_car4;
    }
    if(car == 5){
        return x_car5;
    }
    if(car == 6){
        return x_car6;
    }
    if(car == 7){
        return x_car7;
    }
    if(car == 8){
        return x_car8;
    }
}
function getYcar(car){
    if(car == 1){
        return y_car1;
    }
    if(car == 2){
        return y_car2;
    }
    if(car == 3){
        return y_car3;
    }
    if(car == 4){
        return y_car4;
    }
    if(car == 5){
        return y_car5;
    }
    if(car == 6){
        return y_car6;
    }
    if(car == 7){
        return y_car7;
    }
    if(car == 8){
        return y_car8;
    }
}


async function wait() {
    car1.style.left = "-100%";
    car1.style.top = "212%";
    car5.style.left = "-100%";
    car5.style.top = "252%";

    var first, second, up, down;
    var currentCar1 = 1;
    var currentCar2 = 5;
    var toDelete;
    first = e[0] + a [0][0];
    animateCar(1, -0.2, 1);
    second = e[1] + a[1][0];
    animateCar(1, 0.2, 5);
    console.log(x_car1 + " " + x_car5);
    for(let i = 1; i < 3; i++){
        await sleep(3000);
        up = min(first + a[0][i], second + t[1][i] + a[0][i]);
	    down = min(second + a[1][i], first + t[0][i] + a[1][i]);
        if(up == first + a[0][i] && down == second + a[1][i])
        {
            animateCar(1, 0, currentCar1);
            animateCar(1, 0, currentCar2);
        }
        else if(up == second + t[1][i] + a[0][i] && down == second + a[1][i])
        {
            toDelete = currentCar1;
            currentCar1 = bringCar(currentCar2);
            returnToStart(toDelete);
            animateCar(1, -2.2, currentCar1);
            animateCar(1, 0, currentCar2);
        }
        else if(up == first + a[0][i] && down == first + t[0][i] + a[1][i])
        {
            toDelete = currentCar2;
            currentCar2 = bringCar(currentCar1);
            returnToStart(toDelete);
            animateCar(1, 0, currentCar1);
            animateCar(1, 2.2, currentCar2);
        }
        else if(up == first + a[0][i] && down == first + t[0][i] + a[1][i]){
            var aux = currentCar1;
            var toDelete2 = currentCar2;
            currentCar1 = bringCar(currentCar2);
            currentCar2 = bringCar(aux);
            returnToStart(aux);
            returnToStart(toDelete2);
            animateCar(1, -2.2, currentCar1);
            animateCar(1, 2.2, currentCar2);
        }
        first = up;
	    second = down;
    }
    await sleep(3000);
    animateCar(1, 0.4, currentCar1);
    
    animateCar(1, -0.4, currentCar2);
    await sleep(3000);
}
function min(a, b){

    llamadas = llamadas + 1;
    maxi.value =""+ (llamadas);
    return (a <= b) ? a : b;
}
//solucion bruta

async function bruteSolution(){
    car1.style.left = "-100%";
    car1.style.top = "213%";
    car5.style.left = "-227%";
    car5.style.top = "247%";
    x_car1 = -100;
    y_car1  = 213;
    x_car5 = -227;
    y_car5 = 247;
    var first, second, up, down;
    var currentCar1 = 1;
    var currentCar2 = 5;
    var toBringx, toBringy;
    var str1, str2, str3, str4, str5;
    first = e[0] + a [0][0];
    animateCar(3.7, -1.5, 1);
    second = e[1] + a[1][0];
    animateCar(3.7, 1.5, 5);
    firstt.value = ""+first;
    secondd.value = ""+second;
    for(let i = 1; i < 3; i++){
        await sleep(4000);
        str1 = first+a[0][i];
        str2 = ""+str1
        str3 = second+t[1][i]+a[0][i];
        str4 = ""+str3;
        upp.value = str2 +" o " +str4;
        str1 = second+ a[1][i];
        str2 = ""+ str2;
        str3 = first+t[0][i]+ a[1][i];
        str4 = ""+str3
        downn.value =str2+" o " +str4;
        up = min(first + a[0][i], second + t[1][i] + a[0][i]);
	    down = min(second + a[1][i], first + t[0][i] + a[1][i]);
        
        
        if(up == first + a[0][i] && down == second + a[1][i]){
            animateCar(4.4, 0, currentCar1);
            animateCar(4.4, 0, currentCar2);
        }
        else if(up == second + t[1][i] + a[0][i] && down == second + a[1][i]){
            toBringx = getXcar(currentCar2);
            toBringy = getYcar(currentCar2);
            returnToStart(currentCar1);
            animateCar(4.4, 0, currentCar2);        
            currentCar1 = bringCar(toBringx, toBringy);
            animateCar(4.4, -5, currentCar1);
            
        }
        else if(up == first + a[0][i] && down == first + t[0][i] + a[1][i]){
            toBringx = getXcar(currentCar1);
            toBringy = getYcar(currentCar1);
            returnToStart(currentCar2);
            animateCar(4.4, 0, currentCar1);
            currentCar2 = bringCar(toBringx, toBringy);
            animateCar(4.4, 5, currentCar2);
        }
        else if(up == first + a[0][i] && down == first + t[0][i] + a[1][i]){
            toBringx = getXcar(currentCar1);
            toBringy = getYcar(currentCar1);
            var aux = currentCar1;
            var toDelete2 = currentCar2;
            currentCar1 = bringCar(toBringx, toBringy);
            toBringx = getXcar(aux);
            toBringy = getYcar(aux);
            currentCar2 = bringCar(toBringx, toBringy);
            returnToStart(aux);
            returnToStart(toDelete2);
            animateCar(4.4, -5, currentCar1);
            animateCar(4.4, 5, currentCar2);
        }
        first = up;
	    second = down;
        firstt.value = ""+first;
        secondd.value = ""+second;
    }
    await sleep(3000);
    animateCar(4.4, 1.6, currentCar1);
    
    animateCar(4.4, -1.6, currentCar2);
    await sleep(3000);
    first = first +x[0];
    second = second+x[1];
    firstt.value = ""+first;
    secondd.value = ""+ second;
    upp.value = "";
    downn.value = "";
    var hola = min(first, second);
    console.log(hola);
}
//var a = [[8,10,4], [9,6,7]];

//var t = [[0,2,3], [0,2,1]];
//var e = [3,5], x = [2,1];
async function demoSolution(){
    var estacion1 = 8;
    var estacion2 = 10;
    var estacion3 = 4;
    var estacion4 = 9;
    var estacion5 = 6;
    var estacion6 = 7;
    var estacion7 = 3;
    var estacion8 = 5;
    var estacion9 = 2;
    var estacion10 = 1;
    var estacion11 = 2;
    var estacion12 = 3;
    var estacion13 = 2;
    var estacion14 = 1;
    var estacionobt1 = document.getElementById("estacion1obtenida");//a00
    var estacionobt2 = document.getElementById("estacion2obtenida");//a01
    var estacionobt3 = document.getElementById("estacion3obtenida");//a02
    var estacionobt4 = document.getElementById("estacion4obtenida");//a10
    var estacionobt5 = document.getElementById("estacion5obtenida");//a11
    var estacionobt6 = document.getElementById("estacion6obtenida");//a12
    var estacionobt7 = document.getElementById("estacion7obtenida");//e0
    var estacionobt8 = document.getElementById("estacion8obtenida");//e1
    var estacionobt9 = document.getElementById("estacion9obtenida");//s0
    var estacionobt10 = document.getElementById("estacion10obtenida");//s1
    var estacionobt11 = document.getElementById("estacion11obtenida");//t00
    var estacionobt12 = document.getElementById("estacion12obtenida");//t01
    var estacionobt13 = document.getElementById("estacion13obtenida");//t10
    var estacionobt14 = document.getElementById("estacion14obtenida");//t11
    estacionobt1.value = "Costo:   "+ estacion1;
    estacionobt2.value = "Costo:   "+ estacion2;
    estacionobt3.value = "Costo:   "+ estacion3;
    estacionobt4.value = "Costo:   "+ estacion4;
    estacionobt5.value = "Costo:   "+ estacion5;
    estacionobt6.value = "Costo:   "+ estacion6;
    estacionobt7.value = "Costo:   "+ estacion7;
    estacionobt8.value = "Costo:   "+ estacion8;
    estacionobt9.value = "Costo:   "+ estacion9;
    estacionobt10.value = "Costo:   "+ estacion10;
    estacionobt11.value = ""+ estacion11;
    estacionobt12.value = ""+ estacion12;
    estacionobt13.value = ""+ estacion13;
    estacionobt14.value = ""+ estacion14;
    a[0][0] = estacion1;
    a[0][1] = estacion2;
    a[0][2] = estacion3;

    a[1][0] = estacion4;
    a[1][1] = estacion5;
    a[1][2] = estacion6;

    t[0][1] = estacion11;
    t[0][2] = estacion12;

    t[1][1] = estacion13;
    t[1][2] = estacion14;

    e[0] = estacion7;
    e[1] = estacion8;

    x[0] = estacion9;
    x[1] = estacion10;
    sleep(100);
    bruteSolution();
}
async function displaySolution() {
    var estacion1 = document.getElementById("estacion1").value;
    var estacion2 = document.getElementById('estacion2').value;
    var estacion3 = document.getElementById('estacion3').value;
    var estacion4 = document.getElementById('estacion4').value;
    var estacion5 = document.getElementById('estacion5').value;
    var estacion6 = document.getElementById('estacion6').value;
    var estacion7 = document.getElementById('estacion7').value;
    var estacion8 = document.getElementById('estacion8').value;
    var estacion9 = document.getElementById('estacion9').value;
    var estacion10 = document.getElementById('estacion10').value;
    var estacion11 = document.getElementById('estacion11').value;
    var estacion12 = document.getElementById('estacion12').value;
    var estacion13 = document.getElementById('estacion13').value;
    var estacion14 = document.getElementById('estacion14').value;
    var estacionobt1 = document.getElementById("estacion1obtenida");//a00
    var estacionobt2 = document.getElementById("estacion2obtenida");//a01
    var estacionobt3 = document.getElementById("estacion3obtenida");//a02
    var estacionobt4 = document.getElementById("estacion4obtenida");//a10
    var estacionobt5 = document.getElementById("estacion5obtenida");//a11
    var estacionobt6 = document.getElementById("estacion6obtenida");//a12
    var estacionobt7 = document.getElementById("estacion7obtenida");//e0
    var estacionobt8 = document.getElementById("estacion8obtenida");//e1
    var estacionobt9 = document.getElementById("estacion9obtenida");//s0
    var estacionobt10 = document.getElementById("estacion10obtenida");//s1
    var estacionobt11 = document.getElementById("estacion11obtenida");//t00
    var estacionobt12 = document.getElementById("estacion12obtenida");//t01
    var estacionobt13 = document.getElementById("estacion13obtenida");//t10
    var estacionobt14 = document.getElementById("estacion14obtenida");//t11
    estacionobt1.value = "Costo:   "+ " "+estacion1;
    estacionobt2.value = "Costo:   "+ estacion2;
    estacionobt3.value = "Costo:   "+ estacion3;
    estacionobt4.value = "Costo:   "+ estacion4;
    estacionobt5.value = "Costo:   "+ estacion5;
    estacionobt6.value = "Costo:   "+ estacion6;
    estacionobt7.value = "Costo:   "+ estacion7;
    estacionobt8.value = "Costo:   "+ estacion8;
    estacionobt9.value = "Costo:   "+ estacion9;
    estacionobt10.value = "Costo:   "+ estacion10;
    estacionobt11.value = ""+ estacion11;
    estacionobt12.value = ""+ estacion12;
    estacionobt13.value = ""+ estacion13;
    estacionobt14.value = ""+ estacion14;
    a[0][0] = parseInt(estacion1);
    a[0][1] = parseInt(estacion2);
    a[0][2] = parseInt(estacion3);

    a[1][0] = parseInt(estacion4);
    a[1][1] = parseInt(estacion5);
    a[1][2] = parseInt(estacion6);

    t[0][1] = parseInt(estacion11);
    t[0][2] = parseInt(estacion12);

    t[1][1] = parseInt(estacion13);
    t[1][2] = parseInt(estacion14);

    e[0] = parseInt(estacion7);
    e[1] = parseInt(estacion8);

    x[0] = parseInt(estacion9);
    x[1] = parseInt(estacion10);
    sleep(100);
    bruteSolution();
}