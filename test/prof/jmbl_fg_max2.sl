(set-logic LIA)

(synth-fun mux_2 ((x Int) (y Int)) Int
    ((y_int Int) (y_bool Bool) (y_const_int Int) (y_const_bool Bool))
    ((y_bool Bool ((= y_int y_int) (> y_int y_int) (>= y_int y_int) (< y_int y_int) (<= y_int y_int) y_const_bool (not y_bool) (and y_bool y_bool) (or y_bool y_bool) (=> y_bool y_bool) (xor y_bool y_bool) (= y_bool y_bool) (ite y_bool y_bool y_bool)))
    (y_int Int (x y y_const_int (- y_int) (+ y_int y_int) (- y_int y_int) (* y_const_int y_int) (* y_int y_const_int) (div y_int y_const_int) (mod y_int y_const_int) (abs y_int) (ite y_bool y_int y_int)))
    (y_const_int Int (1 2 3 4 5 6 7 8 9 10 11 12))
    (y_const_bool Bool (true false))))

(declare-var x Int)
(declare-var y Int)
(constraint (>= (mux_2 x y) x))
(constraint (>= (mux_2 x y) y))
(constraint (or (= x (mux_2 x y)) (= y (mux_2 x y))))

(check-synth)
