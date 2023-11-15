; default grammar added
(set-logic BV)
(synth-fun inv((s (_ BitVec 32))(l (_ BitVec 32))(n (_ BitVec 32))(x (_ BitVec 32)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 32)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 32)(s l n x (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var l (_ BitVec 32))
(declare-var n (_ BitVec 32))
(declare-var s (_ BitVec 32))
(declare-var s1 (_ BitVec 32))
(declare-var x (_ BitVec 32))
(declare-var x1 (_ BitVec 32))
( constraint  (=> (and (= s (_ bv0 32)) (= x (_ bv0 32))) (inv s l n x )) ) 
( constraint  (=> (and (and (inv s l n x ) (= s1 (bvadd s (_ bv1 32)))) (= x1 (bvadd x (_ bv1 32)))) (or (= s1 x1) (= s1 (_ bv0 32)))) ) 
( constraint  (=> (and (and (inv s l n x ) (= s1 (bvadd s (_ bv1 32)))) (= x1 (bvadd x (_ bv1 32)))) (inv s1 l n x1 )) ) 
(check-synth)
