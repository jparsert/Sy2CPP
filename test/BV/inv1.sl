; default grammar added
(set-logic BV)
(synth-fun inv((x (_ BitVec 4)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 4)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 4)(x (_ bv0 4) (_ bv1 4) (_ bv2 4) (_ bv3 4)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var x (_ BitVec 4))
( constraint  (inv (_ bv0 4) ) ) 
( constraint  (=> (and (inv x ) (not (= (bvadd x (_ bv1 4)) (_ bv10 4)))) (not (= (bvadd x (_ bv1 4)) (_ bv15 4)))) ) 
( constraint  (=> (and (inv x ) (not (= (bvadd x (_ bv1 4)) (_ bv10 4)))) (inv (bvadd x (_ bv1 4)) )) ) 
(check-synth)
