##### EJEMPLO 1: SIMULACION DE UN DADO#####

###Funci?n de masa  y de distribuci?n de probabilidad

p_X<-function(x){
  if(x>=0 & x<=100){
    
  }
}

F_X<-function(x){
  if (x<1){
    0
  } else {
    if (x>=1 & x<2){
      1/6
    } else {
      if (x>=2 & x<3){
        2/6
      } else {
        if (x>=3 & x<4){
          3/6
        } else {
          if (x>=4 & x<5){
            4/6
          } else {
            if (x>=5 & x<6){
              5/6
            } else {
              1
            }
          }
        }
      }
    }
  }
}

###Gr?ficos

mass<-NULL
Dist<-NULL
for (i in -1:8){
  mass<-c(mass,p_X(i))
  Dist<-c(Dist,F_X(i))
}

plot(-1:8,mass,type="h")
lines(-1:8,mass,type="p",pch=16)

plot(-1:8,Dist,type="s")

###Algoritmo para simular

dicesim<-function(u){
  for (i in 1:6){
    if (u>F_X(i-1) & u<=F_X(i)){
      return(i)
    }
  }
}

###Lanzar el dado una vez
u<-runif(1)
dicesim(u)

###Simulaci?n de 10000 realizaciones
vector_u<-runif(10000)
vector_x<-NULL

for (j in 1:10000){
  vector_x[j]<-dicesim(vector_u[j])
}

barplot(table(vector_x))

##### EJEMPLO 2: SIMULACION DE UNA BINOMIAL (n=15, p=0.3)#####

vector_binom<-rbinom(n=10000,size=15,prob=0.3)

barplot(table(vector_binom))

binom_mass<-dbinom(x=0:15,size=15,prob=0.3)

plot(0:15,binom_mass,type="h")

##### EJEMPLO 3: SIMULACION DE UNA POISSON (lambda=4)#####

vector_pois<-rpois(n=10000,lambda=4)

barplot(table(vector_pois))

pois_mass<-dpois(x=0:30,lambda=4)

plot(0:30,pois_mass,type="h")




######################################################

##----------------------------------------------------------------------------##

## Calculo del valor de K

s <- 0
for(n in 1:100){
  s<- s + sqrt(n)/(4+n)
}
K = 1/s
print(K)

# Función de masa
p_X <- function(x){
  if(x>=1 & x<=100){
    return(K*sqrt(x)/(4+x))
  }
  return(0)
}

# Función de dist. acumulada
F_X <- function(x){
  s<-0
  if(x<0){
    return(0)
  }
  if(x<100){
    for(i in 0:x){
      s <- s+p_X(i)
    }
    return(s)
  }
  return(1)
}


# Hist. de las funciones de masa y dist. acumulada

mass<-NULL
Dist<-NULL

for (i in 1:100){
  mass<-c(mass,p_X(i))
  Dist<-c(Dist,F_X(i))
}

plot(1:100,mass,type="h")
lines(1:100,mass,type="p",pch=16)

# Etiquetas de los ejes
xlabel <- 'x'
ylabel <- 'Valor'
title(main = 'Función de masa', xlab = xlabel, ylab = ylabel)

plot(1:100,Dist,type="s")

# Etiquetas de los ejes
xlabel <- 'x'
ylabel <- 'Valor'
title(main = 'Función de distribución acumulada', xlab = xlabel, ylab = ylabel)


# Simulacion de la empanada en base a un valor u (0<=u<=1)

empanada_sim <- function(u){
  for(i in 1:100){
    if(u>F_X(i-1) & u<=F_X(i)){
      return(i)
    }
  }
}

# Ejecutar 100 realizaciones de la simulación
vector_u<-runif(1000)
vector_x<-NULL

for (j in 1:1000){
  vector_x[j]<-empanada_sim(vector_u[j])
}



barplot(table(vector_x))

xlabel <- 'x'
ylabel <- 'Frequency'
title(main = 'Simulación de 1.000 realizaciones', xlab = xlabel, ylab = ylabel)

# Ganancia en función de x (demanda) y q (empanadas elaboradas)

G<-function(x, q){
  total <- 0
  if(q<=x){
    total <- 1500*q
  }
  else{
    total <- 1500*x
    total <- total + 600*(q-x)
  }
  total <- total - 900*q
  
  return(total)
}

# Calcular 1000 realizaciones
X_vector = runif(1000)
demanda_vector <- NULL
ganancias <- NULL

for(x in 1:1000){
  demanda_vector[x]<-empanada_sim(X_vector[x])
  ganancias[x] <- G(demanda_vector[x],42) # el segundo argumento es el valor de q
}
ganancias

plot(1:1000,ganancias,type="s")
barplot(table(ganancias))

xlabel <- 'x'
ylabel <- 'Frequency'
title(main = paste('Simulación de 1000 ventas'))


E_g<-function(q){
  v_E <- 0
  for(i in 1:1000){
    v_E <- v_E+ G(empanada_sim(X_vector[i]),q)
  }
  return(v_E/1000)
}

valores_e <- NULL
for(i in 1:100){
  valores_e[i] <- E_g(i)
}
X_vector
valores_e

plot(1:100,valores_e,type="s")
xlabel <- 'x'
ylabel <- 'Frequency'
title(main = paste('Ganancia esperada con q de 1:100'))


u_vector <- runif(1000)
x_vector <- NULL
for(i in 1:1000){
  x_vector[i] <- 
}

cuantiles <-NULL
for(q in 1:100){
  ganancias <- NULL
  for(x in 1:1000){
    ganancias[x] <- G(empanada_sim(X_vector[x]),q)
  }
  cuantil <- quantile(ganancias,probs = seq(0, 1, 0.1))
  cuantiles[q]<-unname(cuantil[2])
}


demanda <- NULL
for(q in 1:1000){
  demanda[q] <- empanada_sim(X_vector[q])
}



cuantil <- quantile(ganancias,probs = seq(0, 1, 0.1))
(cuantil)

plot(1:100,cuantiles,type="s")

xlabel <- 'x'
ylabel <- 'Frequency'
title(main = paste('Simulación de 100 q'))

cuantiles
barplot(table(cuantiles))

table(ganancias)



E<-function(){
  v_E <- 0
  for(i in 1:100){
    v_E <- v_E+ i*p_X(i)
  }
  return(v_E)
}

E()
