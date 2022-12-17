(set-logic LIA)

(synth-fun inv ((s Int) (l Int) (n Int) (x Int)) Bool
    ((Start Bool) (AtomicFormula Bool) (Sum Int) (Term Int) (Sign Int) (Var Int) (Const Int))
    ((Start Bool ((and AtomicFormula AtomicFormula) (or AtomicFormula AtomicFormula)))
    (AtomicFormula Bool ((<= Sum Const) (= Sum Const)))
    (Sum Int ((+ Term Term)))
    (Term Int ((* Sign Var)))
    (Sign Int (0 1 (- 1)))
    (Var Int (s l n x))
    (Const Int ((+ Const Const) (- Const Const) 0 1))))

(define-fun implies ((b1 Bool) (b2 Bool)) Bool
    (or (not b1) b2))
(define-fun and3 ((b1 Bool) (b2 Bool) (b3 Bool)) Bool
    (and (and b1 b2) b3))
(define-fun and4 ((b1 Bool) (b2 Bool) (b3 Bool) (b4 Bool)) Bool
    (and (and3 b1 b2 b3) b4))
(define-fun and5 ((b1 Bool) (b2 Bool) (b3 Bool) (b4 Bool) (b5 Bool)) Bool
    (and (and4 b1 b2 b3 b4) b5))
(define-fun and6 ((b1 Bool) (b2 Bool) (b3 Bool) (b4 Bool) (b5 Bool) (b6 Bool)) Bool
    (and (and5 b1 b2 b3 b4 b5) b6))
(define-fun or3 ((b1 Bool) (b2 Bool) (b3 Bool)) Bool
    (or (or b1 b2) b3))
(define-fun or4 ((b1 Bool) (b2 Bool) (b3 Bool) (b4 Bool)) Bool
    (or (or3 b1 b2 b3) b4))
(define-fun or5 ((b1 Bool) (b2 Bool) (b3 Bool) (b4 Bool) (b5 Bool)) Bool
    (or (or4 b1 b2 b3 b4) b5))
(declare-var l Int)
(declare-var s Int)
(declare-var n Int)
(declare-var x Int)
(declare-var s1 Int)
(declare-var x1 Int)
(constraint (implies (and (= s 0) (= x 0)) (inv s l n x)))
(constraint (implies (and3 (inv s l n x) (= s1 (+ s 1)) (= x1 (+ x 1))) (or (= s1 x1) (= s1 0))))
(constraint (implies (and3 (inv s l n x) (= s1 (+ s 1)) (= x1 (+ x 1))) (inv s1 l n x1)))

(check-synth)
