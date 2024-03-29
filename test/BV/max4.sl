; default grammar added
(set-logic BV)
(synth-fun max4((x (_ BitVec 32))(y (_ BitVec 32))(z (_ BitVec 32))(w (_ BitVec 32)))
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)(x y z w (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var w (_ BitVec 32))
(declare-var x (_ BitVec 32))
(declare-var y (_ BitVec 32))
(declare-var z (_ BitVec 32))
( constraint  (bvuge (max4 x y z w ) x) ) 
( constraint  (bvuge (max4 x y z w ) y) ) 
( constraint  (bvuge (max4 x y z w ) z) ) 
( constraint  (bvuge (max4 x y z w ) w) ) 
( constraint  (or (= x (max4 x y z w )) (or (= y (max4 x y z w )) (or (= z (max4 x y z w )) (= w (max4 x y z w ))))) ) 
(check-synth)
