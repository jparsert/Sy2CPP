; default grammar added
(set-logic BV)
(synth-fun comm((x (_ BitVec 8))(y (_ BitVec 8)))
 (_ BitVec 8)
(( NTnonbool (_ BitVec 8))(NTbool Bool))
((NTnonbool (_ BitVec 8)(x y (_ bv0 8) (_ bv1 8) (_ bv2 8) (_ bv3 8)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var x (_ BitVec 8))
(declare-var y (_ BitVec 8))
( constraint  (= (comm x y ) (comm y x )) ) 
(check-synth)
