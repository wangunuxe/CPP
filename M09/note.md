# Module 09 — STL : Présentation des trois exercices

## Exercice 00 — Bitcoin Exchange

### Sujet
Le programme `btc` doit calculer la valeur d'une certaine quantité de bitcoin à une
date donnée, à partir d'une base de données historique (`data.csv`) et d'un fichier
d'entrée fourni par l'utilisateur (`date | valeur`). Si la date demandée n'existe pas
dans la base, il faut utiliser **la date la plus proche antérieure** (jamais une date
future).

### Conteneur utilisé
`std::map<std::string, double>` — un conteneur associatif trié automatiquement par
clé. Comme le format `AAAA-MM-JJ` respecte l'ordre chronologique lorsqu'il est
comparé comme une chaîne de caractères, le tri alphabétique du `map` correspond
exactement au tri chronologique.

### Logique du code
1. `loadDatabase()` lit `data.csv` et remplit `_db` (date → taux de change).
2. `processInput()` lit chaque ligne du fichier utilisateur, valide le format de la
   date et de la valeur (via `isValidDate` et `parseValue`), puis appelle `getRate()`.
3. `getRate()` utilise `_db.lower_bound(date)` pour trouver la première clé
   **supérieure ou égale** à la date recherchée. Si ce n'est pas une correspondance
   exacte, on recule d'un élément (`--it`) pour obtenir la date antérieure la plus
   proche.
4. Chaque ligne est traitée indépendamment : une erreur sur une ligne n'interrompt
   pas le traitement des lignes suivantes.

---

## Exercice 01 — Reverse Polish Notation (RPN)

### Sujet
Le programme `RPN` évalue une expression mathématique écrite en notation polonaise
inversée (ex. `"8 9 * 9 -"`), fournie comme unique argument. Il gère les opérateurs
`+ - * /`, sans parenthèses ni nombres décimaux.

### Conteneur utilisé
`std::stack<int>` — un adaptateur de conteneur (LIFO, « dernier entré, premier
sorti »), basé par défaut sur `std::deque`. Sa sémantique correspond exactement à
l'algorithme d'évaluation RPN.

### Logique du code
1. L'expression est découpée en *tokens* via `std::istringstream`.
2. Pour chaque token :
   - un chiffre est empilé (`push`) ;
   - un opérateur déclenche le dépilement (`pop`) des deux valeurs les plus
     récentes, le calcul, puis l'empilement du résultat.
3. À la fin, la pile doit contenir **exactement un élément** : le résultat final.
   Toute autre situation (pile vide, plusieurs éléments restants, division par
   zéro, jeton invalide) déclenche une exception, capturée dans `main.cpp` pour
   afficher `Error` sur `stderr`.

---

## Exercice 02 — PmergeMe

### Sujet
Le programme `PmergeMe` doit trier une séquence d'entiers positifs en utilisant
l'algorithme **Ford-Johnson** (tri par fusion-insertion), et gérer au moins 3000
entiers différents. Il doit utiliser **deux conteneurs distincts**, chacun avec sa
propre implémentation de l'algorithme (pas de fonction générique), et afficher le
temps de traitement pour chacun.

### L'algorithme Ford-Johnson (merge-insertion sort)
1. **Appariement** : les éléments sont regroupés par paires ; dans chaque paire, le
   plus grand (`a`) et le plus petit (`b`) sont identifiés.
2. **Récursion** : la sous-séquence des `a` est triée en appelant l'algorithme sur
   lui-même (c'est la partie « fusion » du nom).
3. **Chaîne principale** : le premier `b` (garanti inférieur à tous les `a`) est
   placé en tête de la séquence des `a` triés, formant une chaîne déjà triée.
4. **Insertion des `b` restants** : ils sont insérés un par un par recherche
   binaire, dans un ordre précis déterminé par la **suite de Jacobsthal**
   (`J(k) = J(k-1) + 2×J(k-2)` → 0, 1, 1, 3, 5, 11, 21, 43…). Cet ordre — par
   groupes croissants, et à l'intérieur de chaque groupe du plus grand indice au
   plus petit — minimise le nombre de comparaisons nécessaires, car chaque `b`
   dispose d'une borne de recherche connue (son `a` associé).
5. **Élément isolé** (si le nombre total est impair) : inséré en dernier, par
   recherche binaire complète.

### Différence entre `std::vector` et `std::deque`
| | `std::vector` | `std::deque` |
|---|---|---|
| Mémoire | Un seul bloc **contigu** | Plusieurs blocs **segmentés** |
| Insertion au milieu | Décalage dans un bloc contigu (bon pour le cache CPU) | Décalage à travers des segments (moins bon pour le cache) |
| Performance mesurée | Plus rapide (~24 ms pour 3000 éléments) | Plus lent (~2 à 3 fois plus, ~70 ms) |

Cette différence de performance est justement ce que l'exercice cherche à mettre en
évidence.

### Logique du code
1. `parseInput()` valide les arguments et remplit `_vec` et `_deq` avec les mêmes
   données.
2. `mergeInsertVec()` / `mergeInsertDeq()` implémentent séparément le même
   algorithme Ford-Johnson pour chaque conteneur :
   - appariement (`std::pair<int,int>` pour lier `a` et `b`) ;
   - appel récursif sur les `a` ;
   - **ré-association** des `b` avec les `a` triés (car la récursion change leur
     ordre) — réalisée par recherche de correspondance sur la valeur ;
   - insertion des `b` selon l'ordre calculé par `jacobsthalOrder()` ;
   - à chaque insertion, la position actuelle de l'`a` associé est **recherchée
     dynamiquement** dans la chaîne (et non déduite d'une formule statique), car
     les insertions précédentes peuvent avoir déplacé sa position réelle.
3. `run()` mesure le temps d'exécution de chaque tri avec `std::clock()` et affiche
   les séquences avant/après ainsi que les deux durées.
