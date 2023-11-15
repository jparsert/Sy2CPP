; default grammar added
(set-logic BV)
(synth-fun findIdx((y1 (_ BitVec 32))(y2 (_ BitVec 32))(k1 (_ BitVec 32)))
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)(y1 y2 k1 (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var k (_ BitVec 32))
(declare-var x1 (_ BitVec 32))
(declare-var x2 (_ BitVec 32))
( constraint  (=> (bvult x1 x2) (=> (bvult k x1) (= (findIdx x1 x2 k ) (_ bv0 32)))) ) 
( constraint  (=> (bvult x1 x2) (=> (bvugt k x2) (= (findIdx x1 x2 k ) (_ bv2 32)))) ) 
( constraint  (=> (bvult x1 x2) (=> (and (bvugt k x1) (bvult k x2)) (= (findIdx x1 x2 k ) (_ bv1 32)))) ) 
(check-synth)
