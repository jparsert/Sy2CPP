; default grammar added
(set-logic BV)
(synth-fun max2((x (_ BitVec 32))(y (_ BitVec 32)))
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)(x y (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var x (_ BitVec 32))
(declare-var y (_ BitVec 32))
( constraint  (bvuge (max2 x y ) x) ) 
( constraint  (bvuge (max2 x y ) y) ) 
( constraint  (or (= x (max2 x y )) (= y (max2 x y ))) ) 
(check-synth)
