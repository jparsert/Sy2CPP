; default grammar added
(set-logic BV)
(synth-fun inv((x (_ BitVec 32))(m (_ BitVec 32))(n (_ BitVec 32)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 32)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 32)(x m n (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var m (_ BitVec 32))
(declare-var m1 (_ BitVec 32))
(declare-var n (_ BitVec 32))
(declare-var n1 (_ BitVec 32))
(declare-var x (_ BitVec 32))
(declare-var x1 (_ BitVec 32))
( constraint  (=> (and (= x (_ bv0 32)) (= m (_ bv0 32))) (inv x m n )) ) 
( constraint  (=> (and (and (and (and (inv x m n ) (bvult x n)) (or (= m1 x) (= m1 m))) (= x1 (bvadd x (_ bv1 32)))) (= n1 n)) (inv x1 m1 n1 )) ) 
( constraint  (=> (and (and (inv x m n ) (bvuge x n)) (bvugt n (_ bv0 32))) (and (bvule (_ bv0 32) m) (bvult m n))) ) 
(check-synth)
