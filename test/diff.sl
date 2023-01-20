
(set-logic LIA)
(constraint (= 1 22))
(constraint (=> true false))

(synth-fun f ((x Int) (y Int)) Int
    ((y_int Int) (y_bool Bool) (y_const_int Int) (y_const_bool Bool))
    ((y_bool Bool ((= y_int y_int) (> y_int y_int) (>= y_int y_int) (< y_int y_int) (<= y_int y_int) y_const_bool (not y_bool) (and y_bool y_bool) (or y_bool y_bool) (=> y_bool y_bool) (xor y_bool y_bool) (= y_bool y_bool) (ite y_bool y_bool y_bool)))
    (y_int Int (x y y_const_int (- y_int) (+ y_int y_int) (- y_int y_int) (* y_const_int y_int) (* y_int y_const_int) (div y_int y_const_int) (mod y_int y_const_int) (abs y_int) (ite y_bool y_int y_int)))
    (y_const_int Int (1 2 3 4 5 6 7 8 9 10 11 12))
    (y_const_bool Bool (true false))))

(define-fun foo ((a Int) (b Int)) Int (+ a b))

(declare-var x Int)
(declare-var y Int)
(constraint (= true false))
(constraint (= (f x y) (f y x)))
(constraint (or (= (- x y) (f x y)) (= (- y x) (f x y))))
(constraint (ite (= 1 4) true (= true false)))

;(constraint (asdf true false))

(constraint (forall ((a Int)) true))
(constraint (exists ((b Int)) true))
(constraint (let ((c true)) c))

(check-synth)