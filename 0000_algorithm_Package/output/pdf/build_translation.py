from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.enums import TA_CENTER, TA_JUSTIFY
from reportlab.lib import colors
from reportlab.lib.units import mm
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.cidfonts import UnicodeCIDFont
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, KeepTogether
from reportlab.pdfgen import canvas

out = r'D:\VSCODE\VScode_C_basic_0\0000_algorithm_Package\output\pdf\MCD-ST_Liberty_SW_License_Agreement_V2_繁體中文翻譯.pdf'
pdfmetrics.registerFont(UnicodeCIDFont('STSong-Light'))
styles = getSampleStyleSheet()
title = ParagraphStyle('TitleZh', parent=styles['Title'], fontName='STSong-Light', fontSize=19, leading=28, alignment=TA_CENTER, textColor=colors.HexColor('#17365D'), spaceAfter=4*mm)
sub = ParagraphStyle('SubZh', parent=styles['Normal'], fontName='STSong-Light', fontSize=9, leading=15, alignment=TA_CENTER, textColor=colors.HexColor('#666666'), spaceAfter=8*mm)
head = ParagraphStyle('HeadZh', parent=styles['Heading2'], fontName='STSong-Light', fontSize=12, leading=18, textColor=colors.HexColor('#17365D'), spaceBefore=4*mm, spaceAfter=1.5*mm, keepWithNext=True)
body = ParagraphStyle('BodyZh', parent=styles['BodyText'], fontName='STSong-Light', fontSize=10, leading=17, alignment=TA_JUSTIFY, spaceAfter=2.4*mm, wordWrap='CJK')
small = ParagraphStyle('SmallZh', parent=body, fontSize=8.5, leading=13, textColor=colors.HexColor('#555555'), alignment=TA_CENTER, spaceBefore=6*mm)

sections = [
('使用條款', [
'使用本授權軟體，即表示您同意受本授權協議條款及條件的約束。在閱讀並同意下列條款及條件之前，請勿使用本授權軟體。使用本授權軟體即自動表示接受下列條款及條件。']),
('定義', [
'「授權軟體」：指隨附的軟體／韌體、範例、專案範本及所有相關文件與設計工具；視情況以目的碼及／或原始碼形式授權並交付。',
'「產品」：指您及您終端使用者的產品或系統，以及所有相關文件；該產品或系統包含或整合授權軟體，且該授權軟體或其衍生作品僅且專門在由 ST 製造或為 ST 製造的微控制器裝置上執行。']),
('授權', [
'STMicroelectronics（「ST」）授予您一項有限授權，允許您使用授權軟體。此授權為非專屬、全球、不可轉讓（無論以轉讓或其他方式；但 ST 明確授權者除外）、不可再授權、可撤銷且免權利金。您得：',
'(i) 複製授權軟體的原始碼版本，並製作其衍生作品，唯一目的為開發該授權軟體的版本，且僅供產品使用；',
'(ii) 複製授權軟體的目的碼版本，並製作其衍生作品，唯一目的為設計、開發及製造產品；',
'(iii) 複製授權軟體中的文件部分（包括原始碼檔案中非機密的註解，如適用），並製作其衍生作品，唯一目的為提供產品及其使用方式的文件；',
'(iv) 製造、委託製造、使用、銷售、要約銷售、進口、出口或以其他方式，透過多層通路散布產品。']),
('所有權與著作權', [
'授權軟體、相關文件及其所有副本的所有權均屬於 ST 及／或其授權人。您不得移除授權軟體及其任何副本上的著作權聲明。您同意防止未經授權複製授權軟體及相關文件。']),
('限制', [
'除本協議另有明確規定外，您不得為商業目的，全部或部分銷售、轉讓、再授權、出租、租賃或以其他方式散布授權軟體。',
'您確認並同意，將授權軟體或其任何部分或衍生物用於由非 ST 或非為 ST 製造的處理器，無論是使用、改作、翻譯或轉錄，均構成本協議的重大違約，並須另向 ST 取得授權。',
'除「授權」一節明確允許者外，您不得提供或再授權任何與授權軟體相關及／或以其為基礎的原始碼。',
'您確認並同意，保護授權軟體原始碼有合理採取安全防護措施的必要。若 ST 向您證明其有合理理由相信授權軟體原始碼遭違反本協議使用或散布，ST 得以書面通知要求您證明是否發生該等未授權使用或散布。您應配合並協助 ST 判定是否發生未授權使用或散布，並採取適當措施補救任何未授權使用或散布。']),
('不提供保證', [
'授權軟體係「按現狀」及「含所有瑕疵」提供，不附帶任何明示或默示保證。ST 及其授權人明確否認所有明示、默示或其他形式的保證，包括但不限於適售性、特定用途適用性及不侵害智慧財產權的保證。ST 不保證全部或部分使用授權軟體不會中斷或發生錯誤、符合您的需求，或能與您選擇的硬體及軟體組合一同運作。',
'您有責任判斷授權軟體是否適合您的預定用途或應用，或能否達成預期結果。對於您開發的授權軟體衍生作品，ST 不對您及／或任何第三方負責。',
'ST 未授權任何人就授權軟體作出任何陳述或保證。ST 提供的任何技術、應用或設計資訊或建議、品質特性、可靠性資料或其他服務，均不構成 ST 的任何陳述或保證，也不會變更本免責聲明或保證；ST 提供該等資訊或服務亦不因此產生額外義務或責任。ST 不承擔，也不授權任何其他人代表其承擔與授權軟體相關的其他責任。',
'本協議任何內容均不得解釋為：(i) ST 保證或聲明會維持任何 ST 裝置或其他可搭配授權軟體使用的硬體或軟體之生產，或以任何方式維護或支援授權軟體；或 (ii) ST 及／或其授權人承諾對第三方侵害本協議所授權任何權利的行為提起或進行訴訟，或授予任何人提起或進行此類訴訟的權利。然而，ST 收到任何主張授權軟體或您對授權軟體的使用或散布侵害第三方智慧財產權的索賠、訴訟或程序通知後，有權立即終止本協議。',
'法律默示的所有其他保證、條件或其他條款，均在法律允許的最大範圍內排除。']),
('責任限制', [
'在任何情況下，ST 或其授權人均不對您或任何第三方負擔任何間接、特殊、衍生、附帶、懲罰性或其他損害賠償責任（包括但不限於人工成本、重新認證成本、延誤、利潤損失、收入損失、資料損失、替代商品或服務的採購成本等）；無論該責任係基於契約、侵權或任何其他法律理論，且無論 ST 是否已被告知可能發生此等損害，凡與授權軟體、文件或本協議相關或由此產生者，均同。',
'在任何情況下，ST 依本協議對您或任何第三方承擔的責任（包括任何涉及第三方智慧財產權的請求），就任何訴因而言均不超過 100 美元。本節於法律禁止適用的範圍內不適用。就本節而言，ST 的所有責任應合併計算。']),
('終止', [
'若您重大違反本協議任何條款及條件，且未於該違約發生後 30（三十）日內補正，ST 得隨時終止本授權協議。協議終止後，您應立即銷毀或將授權軟體及文件的所有副本返還 ST。終止後，您仍有權在您於違約日期前已購買、且包含由 ST 製造或為 ST 製造之微控制器裝置的產品中，繼續使用授權軟體。']),
('準據法與管轄權', [
'如發生爭議且未能友好和解，唯一有管轄權者為瑞士日內瓦法院。準據法為瑞士法律。']),
('可分割性', [
'若本協議任何條款於任何時間或因任何原因不可執行或無效，本協議其他條款不受影響；其餘條款仍持續有效，效力如同該不可執行或無效條款從未納入本協議。']),
('權利不放棄', [
'任一方對本協議任何條款違約的放棄，不得視為或解釋為放棄任何其他條款或同一條款後續違約的權利。']),
('轉讓', [
'未經他方事先書面同意（該同意不得無理拒絕），您不得將本協議或您在本協議下的任何權利或義務轉讓給任何第三方。若本協議有效轉讓予第三方，本協議對雙方的繼受人及受讓人均具約束力。']),
('雙方關係', [
'本協議任何內容均不會成立或被視為成立雙方間的合夥、本人與代理人或雇主與員工關係。任一方均無權或無權力以任何方式或為任何目的約束他方、以他方名義訂約，或使他方承擔責任。']),
]

story = [Paragraph('MCD-ST Liberty 軟體授權協議 V2', title), Paragraph('繁體中文翻譯｜原協議日期：2011 年 11 月 16 日', sub), Paragraph('譯文說明：本文件為方便閱讀所作之非官方翻譯；如與英文原文有任何歧異，應以英文原文為準。', body), Spacer(1, 2*mm)]
for h, paras in sections:
    story.append(Paragraph(h, head))
    for p in paras:
        story.append(Paragraph(p.replace('&','&amp;'), body))

def footer(c, doc):
    c.saveState()
    c.setStrokeColor(colors.HexColor('#D9E2F3'))
    c.line(18*mm, 15*mm, A4[0]-18*mm, 15*mm)
    c.setFont('STSong-Light', 8)
    c.setFillColor(colors.HexColor('#666666'))
    c.drawString(18*mm, 10*mm, 'MCD-ST Liberty SW License Agreement V2｜繁體中文翻譯')
    c.drawRightString(A4[0]-18*mm, 10*mm, f'{doc.page}')
    c.restoreState()

doc = SimpleDocTemplate(out, pagesize=A4, rightMargin=20*mm, leftMargin=20*mm, topMargin=18*mm, bottomMargin=22*mm, title='MCD-ST Liberty Software License Agreement V2 - Traditional Chinese Translation', author='OpenAI')
doc.build(story, onFirstPage=footer, onLaterPages=footer)
print(out)
