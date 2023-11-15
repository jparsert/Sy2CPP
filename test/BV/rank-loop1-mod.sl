; default grammar added
(set-logic BV)
(synth-fun R((x (_ BitVec 32)))
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)(x (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var x (_ BitVec 32))
( constraint  (=> (bvugt x (_ bv0 32)) (bvugt (R x ) (_ bv0 32))) ) 
( constraint  (=> (bvugt x (_ bv0 32)) (bvugt (R x ) (R (bvmul x (_ bv2 32)) ))) ) 
(check-synth)
