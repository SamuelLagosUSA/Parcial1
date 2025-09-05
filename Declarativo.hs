import Data.List (sortBy)

alumnos :: [[String]]
alumnos = [["Juan","3.5"],["Lucia","5.0"],["Karen","4.5"],["Samuel","1.0"]]

compararNotas [n1,nota1] [n2,nota2]
    | (read nota1 :: Float) > (read nota2 :: Float) = LT
    | (read nota1 :: Float) < (read nota2 :: Float) = GT
    | otherwise = compare n1 n2
compararNotas _ _ = EQ

resultado = sortBy compararNotas alumnos

main = print resultado
