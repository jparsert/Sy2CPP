; default grammar added
(set-logic BV)
(synth-fun inv((i (_ BitVec 32))(l (_ BitVec 32)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 32)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 32)(i l (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var i (_ BitVec 32))
(declare-var i1 (_ BitVec 32))
(declare-var l (_ BitVec 32))
(declare-var l1 (_ BitVec 32))
(declare-var l2 (_ BitVec 32))
( constraint  (=> (= l (_ bv0 32)) (inv i l )) ) 
( constraint  (=> (and (and (and (and (inv i l ) (=> (= l (_ bv4 32)) (= l1 (_ bv0 32)))) (=> (not (= l (_ bv4 32))) (= l1 l))) (not (or (bvult l1 (_ bv0 32)) (bvuge l1 (_ bv5 32))))) (= l2 (bvadd l1 (_ bv1 32)))) (inv i l2 )) ) 
( constraint  (=> (and (and (and (inv i l ) (=> (= l (_ bv4 32)) (= l1 (_ bv0 32)))) (=> (not (= l (_ bv4 32))) (= l1 l))) (or (bvult l1 (_ bv0 32)) (bvuge l1 (_ bv5 32)))) false) ) 
(check-synth)
