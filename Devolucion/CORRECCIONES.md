# Resumen: INSUFICIENTE

## Implementación: A
```
Implementación de los programas que permitan resolver los problemas propuestos. Prolijidad en el código. Legibilidad de los programas y la documentación.
```
+ Ok cpp, ok notebooks

## Informe: A

```
Claridad, concisión y rigor para expresar las ideas del informe escrito. Estilo, ortografı́a,
composición y armado. Presentación adecuada de los resultados.
```

+ En general, la redacción resulto clara.

+ Para la información que les interesó mostrar, en general la forma de representarla fue adecuada. Lindos graficos.

+ Figuras referenciadas.

- En cuanto a la estructura, falto el resumen. La intro un poco pobre.

## Desarrollo: N
```
Análisis, evaluación y modelado de los problemas propuestos. Aplicación de técnicas
y algoritmos adecuados. Riqueza de las ideas ensayadas y manejo de los problemas
numéricos.

```

+ Consideraron un modelo en donde le aplican una transformación a la feature de latitud
  (podría considerarse feature engineering de alguna forma).

+ Aplicaron k-fold cross validation a sus estimaciones.

+- Buscaron modelos para predecir metros cubiertos y precio. Sin embargo, el criterio
   para la selección de features, en general, quedó un tanto oscuro. Tampoco veo que hayan iterado en búsqueda de modelos más complejos (por ejemplo, combinando features)

+- Incorporaron algunas features. La "cantidad de ambientes" y los comentarios
   "positivos". Sin embargo, no esta del todo explicado y no me queda claro porque comentarios positivos tendria que ver con metros cubiertos. También se podría incorporar alguno de estos a la estimación del precio y sacar conclusiones.

- El planteo de la segmentación no quedó muy claro. Hay una aproximación al usar las
  ciudad de Cancun, pero no está del todo completa.

- En el preprocesamiento de los datos, parece no haber filtrado de outliers. Podrían 
  ensayar iteraciones del modelo sin tenerlos en cuenta.

- Faltaron las metricas adicionales (Por ejemplo, R2, MSE, etc)


## Resultados y discusión: N
```
Corrección de los resultados. Grado de completitud. Experimentos adecuados para analizar el problema estudiado, especialmente (¡pero no excluyentemente!) en los aspectos requeridos por el enunciado. Resultados interesantes, complementarios, patológicos, iluminadores.
Certeza y rigor lógico de la discusión, el análisis y las conclusiones. Se pondrá especial énfasis en aquellas que se desprendan de las experiencias realizadas.
```

- Muestran el ajuste en una muestra previa al entrenamiento de su modelo.
  Si van a querer hacer algo como eso, creo que tendría mas sentido intentar hacer prediccion sobre una muestra reducida (validation set) luego de haber encontrado el modelo con CML (familia y coeficientes)

- Falta comparación entre modelos, discusión sobre errores obtenidos, etc.
