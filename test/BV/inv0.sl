; default grammar added
(set-logic BV)
(synth-fun inv()
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)((_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var x (_ BitVec 32))
( constraint  (bvult (_ bv0 32) inv) ) 
( constraint  (=> (and (bvult x inv) (not (= (bvadd x (_ bv1 32)) (_ bv10 32)))) (not (= (bvadd x (_ bv1 32)) (_ bv255 32)))) ) 
( constraint  (=> (and (bvult x inv) (not (= (bvadd x (_ bv1 32)) (_ bv10 32)))) (bvult (bvadd x (_ bv1 32)) inv)) ) 
(check-synth)
