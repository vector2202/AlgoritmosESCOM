var car1 = document.getElementById('carro1');
var car2 = document.getElementById('carro2');
var car3 = document.getElementById('carro3');
var car4 = document.getElementById('carro4');
var car5 = document.getElementById('carro5');
var car6 = document.getElementById('carro6');
var car7 = document.getElementById('carro7');
var car8 = document.getElementById('carro8');
var naranja = document.getElementById('naranja');
var azul = document.getElementById('azul');
var verde = document.getElementById('verde');
var morado = document.getElementById('morado');
var caminoo = document.getElementById('mejor');
var caminoo2 = document.getElementById('mejor2');
var maxi = document.getElementById('max');
var llamadas = 0;
var vecesQ = 0;
car1.style.position = 'relative';
car2.style.position = 'relative';
car3.style.position = 'relative';
car4.style.position = 'relative';
car5.style.position = 'relative';
car6.style.position = 'relative';
car7.style.position = 'relative';
car8.style.position = 'relative';
var camino_max = 10000000;
var camino_max2 = 10000000;
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
var a = [[0,0,0],[0,0,0]];
var t = [[0,0],[0,0]];
var e = [0,0];
var x = [0,0];

//Click de prueba
document.getElementById('demo').addEventListener('click', demoSolution);
document.getElementById('aplicar').addEventListener('click', aplicarSolution);
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
function bringCar(car){
    if(x_car1 == 0){
        return 1;
    }
    else if(x_car2 == 0){
        car2.style.left = getXcar(car) -100 + "%";
        car2.style.top = getYcar(car) + "%";
        x_car2 = getXcar(car)-100;
        y_car2 = getYcar(car);
        return 2;
    }
    else if(x_car3 == 0){
        car3.style.left = getXcar(car) -210+ "%";
        car3.style.top = getYcar(car) + "%";
        x_car3 = getXcar(car)-210;
        y_car3 = getYcar(car);
        return 3;
    }
    else if(x_car4 == 0){
        car4.style.left = getXcar(car) -210+ "%";
        car4.style.top = getYcar(car) + "%";
        x_car4 = getXcar(car)-190;
        y_car4 = getYcar(car);
        return 4;
    }
    else if(x_car5 == 0){
        car5.style.left = getXcar(car) + "%";
        car5.style.top = getYcar(car) + "%";
        x_car5 = getXcar(car);
        y_car5 = getYcar(car);
        return 5;
    }
    else if(x_car6 == 0){
        car6.style.left = getXcar(car) - 100 + "%";
        car6.style.top = getYcar(car) + "%";
        x_car6 = getXcar(car) - 80;
        y_car6 = getYcar(car);
        return 6;
    }
    else if(x_car7 == 0){
        car7.style.left = getXcar(car) -200 + "%";
        car7.style.top = getYcar(car) + "%";
        x_car7 = getXcar(car)-180;
        y_car7 = getYcar(car);
        return 7;
    }
    else if(x_car8 == 0){
        car8.style.left = getXcar(car)-200 + "%";
        car8.style.top = getYcar(car) + "%";
        x_car8 = getXcar(car)-200;
        y_car8 = getYcar(car);
        return 8;
    }
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
function printCamino(car, camino){
    if(car%4 == 1){
        naranja.value = ""+camino;
    }
    else if(car%4 == 2){
        azul.value = ""+camino;
    }
    else if(car%4 == 3){
        verde.value = ""+camino;
    }
    else if(car%4 == 0){
        morado.value = ""+camino;
    }
}
async function wait(i, car, linea, camino) {
    printCamino(car, camino); 
    
    if(i >= 3){
        if(linea == 0){
            animateCar(5.5, 3.4, car);
            printCamino(car, camino + x[0]);
            meterCamino(camino + x[0]);
            return;
        }
        else{
            animateCar(5.5, -3.4, car);
            printCamino(car, camino + x[1]);
            meterCamino(camino + x[1]);
            return;
        }  
        
    }
    await sleep(5000);
    if(i < 2){
    var nextCar = bringCar(car);
    animateCar(6, 0, car);
    }
    wait(i+1, car, linea, (camino + a[linea][i]));
    if(i < 2){
        await sleep(5000);
        if(linea == 0){
            animateCar(6, 9.5, nextCar);
        }
        else{
            animateCar(4.4, -9.5, nextCar);
        }
    }
    wait(i+1, nextCar, (linea == 0) ? 1 : 0,( camino + t[linea][i] + a[linea][i]));
    var minimo = min(0,9);
    console.log(minimo);
}
function min(a, b){
    console.log("Llamadas: "+ llamadas);
    llamadas = llamadas + 1;
    maxi.value =""+ (llamadas);
    return (a <= b) ? a : b;
}
//solucion bruta
function meterCamino(camino){
    if(vecesQ == 0){
        if(camino < camino_max){
            camino_max = camino;
            caminoo.value = ""+camino_max;
        }
    }
    else{
        if(camino < camino_max2){
            camino_max2 = camino;
            caminoo2.value = ""+camino_max2;
        }  
    }
}
async function bruteSolution(){
    car1.style.left = "-50%";
    car1.style.top = "330%";
    x_car1 = -50;
    y_car1  = 330;
    await sleep(1000);
    animateCar(4.5, -3, 1);
    wait(0, 1, 0, e[0]);
    
    await sleep(35000);
    naranja.value = "";
    azul.value = "";
    verde.value = "";
    morado.value = "";
    returnToStart(1);
    returnToStart(2);
    returnToStart(3);
    returnToStart(4);
    vecesQ = 1;
    car5.style.left = "-50%";
    car5.style.top = "350%";
    x_car5 = -50;
    y_car5 = 350;

    await sleep(1000);
    animateCar(4.5, 3, 5);
    wait(0, 5, 1, e[1]);
    var hola = min(0,1);
    console.log(hola);
}
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
    a[0][0] = estacion1;
    a[0][1] = estacion2;
    a[0][2] = estacion3;

    a[1][0] = estacion4;
    a[1][1] = estacion5;
    a[1][2] = estacion6;

    t[0][0] = estacion11;
    t[0][1] = estacion12;

    t[1][0] = estacion13;
    t[1][1] = estacion14;

    e[0] = estacion7;
    e[1] = estacion8;

    x[0] = estacion9;
    x[1] = estacion10;
    sleep(100);
    bruteSolution();
}
async function aplicarSolution(){
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
    estacionobt1.value = "Costo:   "+estacion1;
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