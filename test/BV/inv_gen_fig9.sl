; default grammar added
(set-logic BV)
(synth-fun inv((x (_ BitVec 32))(y (_ BitVec 32)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 32)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 32)(x y (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var x (_ BitVec 32))
(declare-var y (_ BitVec 32))
(declare-var y1 (_ BitVec 32))
( constraint  (=> (and (= x (_ bv0 32)) (= y (_ bv0 32))) (inv x y )) ) 
( constraint  (=> (and (and (inv x y ) (bvuge y (_ bv0 32))) (= y1 (bvadd y x))) (inv x y1 )) ) 
( constraint  (=> (and (inv x y ) (bvult y (_ bv0 32))) false) ) 
(check-synth)
